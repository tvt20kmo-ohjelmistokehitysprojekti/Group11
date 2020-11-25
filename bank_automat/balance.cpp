#include "balance.h"
#include "ui_balance.h"
#include "mysingleton.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mainwindow.h"
#include "menu.h"

balance::balance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::balance)
{
    ui->setupUi(this);
}

balance::~balance()
{
    delete ui;
}

void balance::on_btnbalance_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    QString balance = ui->labelBalance->text();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/balance/"+idCard));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username="admin";
        QString password="1234";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

           QJsonObject json;
           json.insert("idkortti",idCard);
           json.insert("Saldo", balance);
           QNetworkAccessManager nam;
           QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
           while(!reply->isFinished()) {
               qApp->processEvents();
           }
           QString response_data = reply->readAll();
           qDebug() << response_data;

           reply->deleteLater();

           if(response_data == '1') {
               ui->labelBalance->setText("Tilin saldo on " +balance+ " €.");
           }
           else {
               ui->labelBalance->setText("Tilillä ei ole rahaa.");
           }

}

void balance::on_btnClose_clicked()
{
    this->close();
}

void balance::on_btnBack_clicked()
{
    this->close();
    menu *men = new menu();
    men->show();
}

