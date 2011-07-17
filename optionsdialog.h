#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QString>
#include <QUuid>

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(const QUuid &uuid, QWidget *parent = 0);
    ~OptionsDialog();

private slots:
    void on_pbBrowseImage_clicked();

    void on_buttonBox_accepted();

    void on_pbBrowse_clicked();

    void on_cbResize_stateChanged(int );

private:
    QUuid _uuid;

    Ui::OptionsDialog *ui;
    QString _image_file;
    QString _command;

    void loadSettings();
};

#endif // OPTIONSDIALOG_H
