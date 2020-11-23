#include "menu.h"
#include "ui_menu.h"
#include "withdraw.h"
#include "balance.h"
#include "action.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_btnWithdraw_clicked()
{
    withdraw *wd = new withdraw();
    wd->show();
    this->close();
}

void menu::on_btnBalance_clicked()
{
    balance *bal = new balance();
    bal->show();
    this->close();
}

void menu::on_btnAction_clicked()
{
    action *act = new action();
    act->show();
    this->close();
}

void menu::on_btnClose_clicked()
{
    this->close();
}
