#include <QString>
#include <QDirIterator>
#include <QDebug>

#include "appselector.h"
#include "ui_appselector.h"
#include "desktopfile.h"

#if !defined(Q_WS_MAEMO_5) && !defined(Q_WS_MAEMO_6)
    //for debug
    QString appFilesDir = QString("/usr/share/applications");
#else
    QString appFilesDir = QString("/usr/share/applications/hildon");
#endif

AppSelector::AppSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppSelector)
{
    ui->setupUi(this);
    loadApps();
}

AppSelector::~AppSelector()
{
    delete ui;
}

void AppSelector::loadApps()
{
    QDirIterator it(appFilesDir);
    while (it.hasNext())
    {
        //QString filename = it.next();
        it.next();
        if (! it.fileInfo().isDir())
        {
            //DesktopFile desktopFile(filename); //for future
            new QListWidgetItem(it.fileInfo().baseName(), ui->lwAppSelector);
        }
    }
}

QListWidgetItem* AppSelector::currentItem() const
{
    return ui->lwAppSelector->currentItem();
}
