#ifndef ACTION_H
#define ACTION_H

#include <QWidget>

namespace Ui {
class action;
}

class action : public QWidget
{
    Q_OBJECT

public:
    explicit action(QWidget *parent = nullptr);
    ~action();

private slots:
    void on_btnShowAction_clicked();

    void on_btnBack_clicked();

    void on_btnClose_clicked();

private:
    Ui::action *ui;
};

#endif // ACTION_H
