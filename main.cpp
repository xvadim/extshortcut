#include <QtGui/QApplication>
#if defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
#include "qmaemo5homescreenadaptor/qmaemo5homescreenadaptor.h"
#endif

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setGraphicsSystem("native");

    MainWindow mainWindow;

#if defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
    QMaemo5HomescreenAdaptor *adaptor = new QMaemo5HomescreenAdaptor(&mainWindow);
    adaptor->setSettingsAvailable(true);
    //QObject::connect(adaptor, SIGNAL(homescreenChanged(bool)), &w, SLOT(renewCalendar()));
    QObject::connect(adaptor, SIGNAL(settingsRequested()), &mainWindow, SLOT(showSettingsDialog()));
#endif
    const QStringList args = QApplication::arguments();

    // parse the command line arguments.
    int idx;
    if ((idx = args.indexOf(QLatin1String("-plugin-id"))) != -1)
    {
        mainWindow.setAppletId(args.value(idx + 1));
    }

    mainWindow.show();

    return app.exec();
}
