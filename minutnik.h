#ifndef MINUTNIK_H
#define MINUTNIK_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDateTime>

namespace Ui {
class minutnik;
}

class minutnik : public QDialog
{
    Q_OBJECT

public:
    explicit minutnik(QWidget *parent = nullptr);
    ~minutnik();

private slots:
    void on_rozpocznij_clicked();
    void on_anuluj_clicked();
    void updataTimeAndDisplay();

private:
    Ui::minutnik *ui;
    QTimer *timer;
    QTimer *amin;
    QTimer *bmin;
    QTime czas;
    QString pokStr;
    QString Str;
};

#endif // MINUTNIK_H
