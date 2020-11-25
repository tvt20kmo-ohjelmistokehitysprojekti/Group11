#include "balance.h"
#include "ui_balance.h"
#include "mysingleton.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QNetworkRequest>
#include "mainwindow.h"
#include "menu.h"
#include <QJsonValue>

balance::balance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::balance)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
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

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/balance/"+idCard));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username="admin";
        QString password="1234";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

           QNetworkAccessManager nam;
           QNetworkReply *reply = nam.get(request);
           while(!reply->isFinished()) {
               qApp->processEvents();
           }
           QByteArray response_data = reply->readAll();
           qDebug() << response_data;

           QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
           QJsonObject jsobj = json_doc.object();
           QJsonArray jsarr = json_doc.array();

           QString balance;
           foreach (const QJsonValue &value, jsarr) {
             QJsonObject jsob = value.toObject();
             balance+=jsob["balance"].toString();
             ui->labelBalance->setText("Saldo on: "+balance+" €.");
           }

           reply->deleteLater();

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

