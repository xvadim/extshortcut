#ifndef UTILS_H
#define UTILS_H

bool createLock();
void unLock();

enum MSG_TYPE {MSG_INFO, MSG_WARNING, MSG_ERROR};

void showMessage(QWidget *parent, const QString &msg, MSG_TYPE msgType = MSG_INFO);

#endif // UTILS_H
