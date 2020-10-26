#ifndef STOPER_H
#define STOPER_H

#include <QDialog>
#include <QTimer>
#include <QLCDNumber>

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
    void on_startstoper_clicked();


    void on_stopstoper_clicked();

private:
    Ui::stoper *ui;
    int stpr = 0 ;
   // int to = 20 ;

//protected:

};

#endif // STOPER_H
