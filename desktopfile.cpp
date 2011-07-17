#include <QSettings>

#include "desktopfile.h"

DesktopFile::DesktopFile(const QString &fileName)
{
    QSettings desktopFile(fileName, QSettings::IniFormat);
    desktopFile.beginGroup("Desktop Entry");
    _name = desktopFile.value("Name", "").toString();
}
