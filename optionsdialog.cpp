#include <QFileDialog>
#include <QSettings>
#include <QDebug>
#include <QDesktopServices>
#include <QListWidgetItem>
#include <QPixmap>

#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include "appselector.h"
#include "utils.h"

const int maxImageWidth = 700;
const int maxImageHeight = 400;

OptionsDialog::OptionsDialog(const QUuid &uuid, QWidget *parent) :
    QDialog(parent),
    _uuid(uuid),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
    loadSettings();
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::loadSettings()
{
    QSettings settings;
    settings.beginGroup(_uuid.toString());
    _image_file = settings.value("image_file","").toString();
    ui->pbBrowseImage->setText(_image_file.isEmpty() ? "Select image" : _image_file);
    ui->edCommand->setText(settings.value("command","").toString());
    ui->cbCommandType->setCurrentIndex(settings.value("commandType",0).toInt());
    int imageWidth = settings.value("imageWidth",0).toInt();
    int imageHeight = settings.value("imageHeight",0).toInt();
    if (imageWidth && imageHeight)
    {
        ui->sbWidth->setValue(imageWidth);
        ui->sbHeight->setValue(imageHeight);
        ui->cbResize->setChecked(true);
    }
    ui->edLabel->setText(settings.value("label","").toString());
}

void OptionsDialog::on_pbBrowseImage_clicked()
{
    _image_file = QFileDialog::getOpenFileName(this, tr("Select image"), QString(), tr("Images (*.png *.xpm *.jpg)"));
    if (!_image_file.isEmpty())
    {
        QPixmap img(_image_file);
        if (img.isNull())
            showMessage(this, tr("Error!!\nCan't load image."), MSG_ERROR);
        else
        {
            if ((maxImageWidth < img.width() || maximumHeight() < img.height()) && !ui->cbResize->isChecked())
                showMessage(this, tr("Error!!\nImage is too big. Select another one or set image size."), MSG_ERROR);
            else
                ui->pbBrowseImage->setText(_image_file);
        }
    }
}

void OptionsDialog::on_buttonBox_accepted()
{
    QSettings settings;
    settings.beginGroup(_uuid.toString());
    settings.setValue("image_file", _image_file);
    settings.setValue("command", ui->edCommand->text());
    settings.setValue("commandType", ui->cbCommandType->currentIndex());
    if (ui->cbResize->isChecked())
    {
        settings.setValue("imageWidth", ui->sbWidth->value());
        settings.setValue("imageHeight", ui->sbHeight->value());
    }
    else
    {
        settings.setValue("imageWidth", 0);
        settings.setValue("imageHeight", 0);
    }
    settings.setValue("label", ui->edLabel->text());
    QDialog::accept();
}

void OptionsDialog::on_pbBrowse_clicked()
{
    AppSelector appSelector;
    if (appSelector.exec() == QDialog::Accepted)
    {
        QListWidgetItem *it = appSelector.currentItem();
        if (it)
        {
            ui->edCommand->setText(it->text());
        }
    }
}

void OptionsDialog::on_cbResize_stateChanged(int state)
{
    ui->sbWidth->setEnabled(state);
    ui->sbHeight->setEnabled(state);
}
