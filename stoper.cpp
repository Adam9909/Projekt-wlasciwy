#include "stoper.h"
#include "ui_stoper.h"
#include <iostream>
#include <QTimer>
#include <QTime>
#include <QWidget>

stoper::stoper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stoper)
{
    ui->setupUi(this);

    astop = new QTimer(this);
    bstop = new QTimer(this);
    connect(astop, SIGNAL(timeout()), this, SLOT(updataTimeAndDisplay()));
}
stoper::~stoper()
{
    delete ui;
}

void stoper::updataTimeAndDisplay()
{
    QTime time = QTime::currentTime();
    int t = czas.msecsTo(time);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    pokStr = showTime.toString("mm:ss.zzz");
    ui->lcdNumber->display(pokStr);
}

void stoper::on_startstoper_clicked()
{
    ui->startstoper->setEnabled(false);
    ui->stopstoper->setEnabled(true);
    czas = QTime::currentTime();
    astop->start(1);
}

void stoper::on_stopstoper_clicked()
{
    if(ui->stopstoper->text() == "Stop")
{
    ui->startstoper->setEnabled(false);
    astop->stop();
    ui->stopstoper->setText("Resetuj");
}
    else
{
    ui->lcdNumber->display("00:00.00");
    ui->stopstoper->setText("Stop");
    ui->startstoper->setEnabled(true);
}
}
