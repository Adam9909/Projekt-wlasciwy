#ifndef STOPER_H
#define STOPER_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QWidget>
#include <iostream>
#include <QtGui>
#include <QtCore>


namespace Ui {
class stoper;
}

class stoper : public QDialog
{
    Q_OBJECT

public:
    explicit stoper(QWidget *parent = nullptr);
    ~stoper();

private slots:
    void updataTimeAndDisplay();
    void on_startstoper_clicked();
    void on_stopstoper_clicked();

private:
    Ui::stoper *ui;
    QTimer *astop;
    QTimer *bstop;
    QTime czas;
    QString pokStr;
    QString Str;
};

#endif // STOPER_H
