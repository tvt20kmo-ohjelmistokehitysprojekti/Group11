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

private:
    Ui::balance *ui;
};

#endif // BALANCE_H
