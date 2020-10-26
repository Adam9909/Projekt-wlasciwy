#include "stoper.h"
#include "ui_stoper.h"
#include <QTime>
#include <QTimer>
#include <QLCDNumber>

int to ;

stoper::stoper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stoper)
{
    ui->setupUi(this);

    ui->lcdNumber->display("00:00");

    QTimer *timer = new QTimer(this);
   // connect(timer, &QTimer::timeout, this, &stoper::on_startstoper_clicked);
    timer->start(1000);
    do{stpr++ ;
  } while(stpr<=to);
   // stpr=0;

}

stoper::~stoper()
{
    delete ui;
}



void stoper::on_startstoper_clicked()
{
    QTimer *timer = new QTimer(this);
    timer->start(1000);

    ui->lcdNumber->display(stpr);
    stpr++;
   // do{stpr++ ;
 // } while(stpr<=to);
   // stpr=0;
  //  to = stpr;
}


void stoper::on_stopstoper_clicked()
{
    ui->lcdNumber->display(to);

}
