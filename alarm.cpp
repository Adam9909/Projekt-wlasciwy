#include "alarm.h"
#include "ui_alarm.h"

alarm::alarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarm)
{
    ui->setupUi(this);

    QObject::connect(ui->ustaw, SIGNAL(clicked()), this, SLOT(ustaw));
}

alarm::~alarm()
{
    delete ui;
}

void alarm::on_ustaw_clicked()
{
    ui->label->setText("Ustawiłeś alarm na godzine: ");
}
