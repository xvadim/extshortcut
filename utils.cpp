#include <QFile>
#include <QString>
#include <QWidget>
#include <QMessageBox>
#include <QString>

#include "utils.h"

#if !defined(Q_WS_MAEMO_5) && !defined(Q_WS_MAEMO_6)
    //for debug
    QString lockFileName = QString("/home/vadim/extshortcut.lock");
#else
#   include <QtMaemo5/QMaemo5InformationBox>
    QString lockFileName = QString("/home/user/extshortcut.lock");
#endif

bool createLock()
{
    if (QFile::exists(lockFileName))
        return false;
    QFile file(lockFileName);
    file.open(QIODevice::ReadWrite);
    return true;
}

void unLock()
{
    QFile::remove(lockFileName);
}

void showMessage(QWidget *parent, const QString &msg, MSG_TYPE msgType)
{
#ifdef Q_WS_MAEMO_5
    QString sp("\n\n");
    QMaemo5InformationBox::information(parent, sp + msg + sp, QMaemo5InformationBox::NoTimeout);
#else
    switch (msgType)
    {
        case MSG_INFO:
            QMessageBox::information(parent, ("Qthello"), msg);
            break;
        case MSG_WARNING:
            QMessageBox::warning(parent, ("Qthello"), msg);
            break;
        case MSG_ERROR:
            QMessageBox::critical(parent, ("Qthello"), msg);
            break;
    }//switch
#endif
}
