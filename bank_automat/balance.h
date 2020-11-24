#ifndef BALANCE_H
#define BALANCE_H

#include <QWidget>

namespace Ui {
class balance;
}

class balance : public QWidget
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

private slots:
    void on_btnbalance_clicked();

    void on_btnBack_clicked();

    void on_btnClose_clicked();

    void on_labelbalance_linkActivated(const QString &link);

private:
    Ui::balance *ui;
};

#endif // BALANCE_H
