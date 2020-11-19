#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>
#include "menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLogin_clicked()
{
    QString loginCardID, loginPinCode;
    loginCardID = ui->lineEditCardID->text();
    loginPinCode = ui->lineEditPinCode->text();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/login/?idcard="+loginCardID+"&pinCode="+loginPinCode));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit());

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        qDebug() << "DATA:" +response_data;

        reply->deleteLater();

        if(response_data.compare("true") == 0) {
            menu *men = new menu();
            men->show();
        }
        else {
            ui->labelInfo->setText("Väärä ID tai PIN-koodi. Yritä uudelleen.");
            ui->lineEditCardID->clear();
            ui->lineEditPinCode->clear();
        }
}
