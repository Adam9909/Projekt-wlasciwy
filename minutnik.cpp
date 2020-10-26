#include "minutnik.h"
#include "ui_minutnik.h"

minutnik::minutnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::minutnik)
{
    ui->setupUi(this);
}

minutnik::~minutnik()
{
    delete ui;
}

