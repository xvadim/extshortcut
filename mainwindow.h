// checksum 0x9a77 version 0x30001
/*
  This file was generated by the Mobile Qt Application wizard of Qt Creator.
  MainWindow is a convenience class containing mobile device specific code
  such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include <QPoint>
#include <QUuid>

class QLabel;
class QSettings;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void showExpanded();
    QSize sizeHint() const;

    void setAppletId(const QString &appletId)
    {
        _appletId = appletId;
    }

protected:
    void mousePressEvent(QMouseEvent *event);
    void moveEvent(QMoveEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:
    void showSettingsDialog();
    void initialMove();

private:
    void loadSettings();
    void loadSettingsStage2(bool updatePos = false);
    void launchApplication() const;
    QUuid findUuid();
    QUuid findUuidById();

private:
    enum {SC_TYPE_APPLICATION, SC_TYPE_URL};

    QLabel *_lbCmd;
    QLabel *_lbLabel;
    QUuid _uuid;

    QString _command;
    int     _commandType;
    int _imageWidth;
    int _imageHeight;
    QString _label;
    QPoint _initialPoint;
    QString _appletId;
};

#endif // MAINWINDOW_H
