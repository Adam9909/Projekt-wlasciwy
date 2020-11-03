#ifndef ALARM_H
#define ALARM_H

#include <QDialog>

namespace Ui {
class alarm;
}

class alarm : public QDialog
{
    Q_OBJECT

public:
    explicit alarm(QWidget *parent = nullptr);
    ~alarm();

private slots:
    void on_ustaw_clicked();

private:
    Ui::alarm *ui;
    int godz;
    int zap;
};

#endif // ALARM_H
