#ifndef MINUTNIK_H
#define MINUTNIK_H

#include <QDialog>

namespace Ui {
class minutnik;
}

class minutnik : public QDialog
{
    Q_OBJECT

public:
    explicit minutnik(QWidget *parent = nullptr);
    ~minutnik();

private:
    Ui::minutnik *ui;
};

#endif // MINUTNIK_H
