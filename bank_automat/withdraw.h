#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>

namespace Ui {
class withdraw;
}

class withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_btnWithdraw20_clicked();

    void on_btnWithdraw40_clicked();

    void on_btnWithdraw50_clicked();

    void on_btnWithdraw100_clicked();

    void on_btnWithdrawAmount_clicked();

    void on_btnClose_clicked();

    void on_pushButton_clicked();

    void on_btnBack_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
