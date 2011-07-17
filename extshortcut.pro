# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE331D3E9

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=
QT += maemo5

CONFIG += qdbus

SOURCES += main.cpp mainwindow.cpp \
    optionsdialog.cpp \
    utils.cpp \
    appselector.cpp \
    desktopfile.cpp
 HEADERS += mainwindow.h \
    optionsdialog.h \
    utils.h \
    appselector.h \
    desktopfile.h
FORMS += \
    optionsdialog.ui \
    appselector.ui

#maemo5:contains( DEFINES, Q_WS_MAEMO_5):
#include(./qmaemo5homescreenadaptor/qmaemo5homescreenadaptor.pri)

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()
