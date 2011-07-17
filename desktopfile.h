#ifndef DESKTOPFILE_H
#define DESKTOPFILE_H
#include <QString>

class DesktopFile
{
public:
    DesktopFile(const QString &fileName);
    QString name() const;

private:
    QString _name;
};

inline
QString DesktopFile::name() const
{
    return _name;
}

#endif // DESKTOPFILE_H
