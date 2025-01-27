#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_alarm_clicked();



    void paintEvent(QPaintEvent *event) override;

    void on_stoper_clicked();

    void on_minutnik_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
