#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QWidget>
#include <alarm.h>
#include <stoper.h>
#include <minutnik.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    timer->start(1000); // czas wskazówek

    setWindowTitle(tr("Analog Clock"));
    resize(650, 500);  // wielkość okna

  // QObject::connect(ui->stoper, SIGNAL(clicked()), this, SLOT(on_stoper_clicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPoint godzinowa[3] = {
        QPoint(7, 8),
        QPoint(-3, 8),  //grubość wskazówek
        QPoint(0, -40)  // długość wskazówek
    };
    QPoint minutowa[3] = {
        QPoint(7, 8),
        QPoint(-3, 8),
        QPoint(0, -70)
    };
    QPoint sekundowa [3] = {
        QPoint(7, 8),
        QPoint(-3, 8),
        QPoint(0, -70)
    };
    QColor godzinowaColor(127, 0, 127);
    QColor minutowaColor(0, 127, 127, 191);
    QColor sekundowaColor(127, 0, 165, 110);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 300.0, side / 300.0);
    
  //if state == 'clicked';
            
    painter.setPen(Qt::NoPen);
    painter.setBrush(godzinowaColor);
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0 )));
    painter.drawConvexPolygon(godzinowa, 3);
    painter.restore();
    painter.setPen(godzinowaColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine( 88, 0, 96, 0 );
        painter.rotate(30.0);
    }
    painter.drawText( -7, -100, QString("12"));
    painter.drawText(100, 5, QString("3"));          // cyfry na tarczy
    painter.drawText( -4, 110, QString("6"));
    painter.drawText(-110, 5, QString("9"));

    painter.setPen(Qt::NoPen);
    painter.setBrush(minutowaColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minutowa, 3);
    painter.restore();
    painter.setPen(minutowaColor);

    for (int j = 0; j < 60; ++j) {
        if ((j% 5) != 0)
        painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(sekundowaColor);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(sekundowa, 3);
    painter.restore();
    painter.setPen(sekundowaColor);

    for (int k = 0; k < 60; ++k) {
        painter.drawLine(95, 0, 96, 0);
        painter.rotate(6.0);
    }
}


void MainWindow::on_alarm_clicked()
{
    int res;
    alarm pd(this);
    res = pd.exec();
}

void MainWindow::on_stoper_clicked()
{
    int res;
    stoper pd(this);
    res = pd.exec();
}

void MainWindow::on_minutnik_2_clicked()
{
    int res;
    minutnik pd(this);
    res = pd.exec();
}
