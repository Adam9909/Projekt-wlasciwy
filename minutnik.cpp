#include "minutnik.h"
#include "ui_minutnik.h"
#include <QTimer>
#include <QTime>
#include <QTimeEdit>
#include <QDateTime>
#include <QElapsedTimer>


minutnik::minutnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::minutnik)
{
    ui->setupUi(this);

    amin = new QTimer(this);
    bmin = new QTimer(this);
    connect(amin, SIGNAL(timeout()), this, SLOT(updataTimeAndDisplay()));
}

minutnik::~minutnik()
{
    delete ui;
}

void minutnik::updataTimeAndDisplay()
{
    QTime time = QTime::currentTime();
    int t = czas.msecsTo(time);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    pokStr = showTime.toString("hh:mm:ss");
    ui->label->setText(pokStr);
}

void minutnik::on_rozpocznij_clicked()
{
    class QDateTime ola = ui->timeEdit->dateTime();
    QTime ula = ola.time();
    QString Str = ula.toString("hh:mm:ss");
    ui->label->setText(ula.toString("hh:mm:ss"));
    ui->rozpocznij->setEnabled(true);
    //amin->start(1000);
    startTimer(-1000);

}

void minutnik::on_anuluj_clicked()
{

}
