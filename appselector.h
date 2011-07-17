#ifndef APPSELECTOR_H
#define APPSELECTOR_H

#include <QDialog>

namespace Ui {
    class AppSelector;
}

class QListWidgetItem;

class AppSelector : public QDialog
{
    Q_OBJECT

public:
    explicit AppSelector(QWidget *parent = 0);
    ~AppSelector();
    QListWidgetItem *currentItem() const;

private:
    Ui::AppSelector *ui;

private:
    void loadApps();
};

#endif // APPSELECTOR_H
