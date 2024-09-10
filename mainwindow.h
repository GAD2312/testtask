#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <stdlib.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:

   void clickOnPushButton_number();//Ввод числа
   void clickOnPushButton_dot();
   void clickOnPushButton_firstTermOperation();
   void clickOnPushButton_CE();
   void mathOperations();
   void clickOnPushButton_isEqualTo();
   void calculation(int key);



};
#endif // MAINWINDOW_H
