#include "mainwindow.h"
#include "ui_mainwindow.h"

double termFirst, hiddenAnswer;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(clickOnPushButton_number()));

    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(clickOnPushButton_dot()));

    connect(ui->pushButton_plusMinus,SIGNAL(clicked()),this,SLOT(clickOnPushButton_firstTermOperation()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(clickOnPushButton_firstTermOperation()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(mathOperations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(mathOperations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(mathOperations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(mathOperations()));

    connect(ui->pushButton_CE,SIGNAL(clicked()),this,SLOT(clickOnPushButton_CE()));
    connect(ui->pushButton_isEqualTo,SIGNAL(clicked()),this,SLOT(clickOnPushButton_isEqualTo()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clickOnPushButton_number()
{
    QPushButton  *button = (QPushButton *)sender();

    double term;
    QString labelTerm;

    if (ui->label->text().contains(".") && button->text() == "0"){
       labelTerm = ui->label->text() + button->text();
    }

    else{
    term = (ui->label->text() + button->text()).toDouble();
    labelTerm = QString::number(term);
    }
    ui->label->setText(labelTerm);

}

void MainWindow::clickOnPushButton_dot()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}


void MainWindow::clickOnPushButton_firstTermOperation()
{
    QPushButton  *button = (QPushButton *)sender();

    double term;
    QString labelTerm;

    if(button->text() == "+/-"){
        term = (ui->label->text()).toDouble();
        term = term * -1;
        labelTerm = QString::number(term);

        ui->label->setText(labelTerm);
    }
    else if(button->text() == "%"){
        term = (ui->label->text()).toDouble();
        term = term * 0.01;
        labelTerm = QString::number(term);

        ui->label->setText(labelTerm);
    }

}

void MainWindow::mathOperations()
{
    QPushButton  *button = (QPushButton *)sender();

    termFirst = ui->label->text().toDouble();
    ui->label->setText("");

    button->setChecked(true);
}


void MainWindow::clickOnPushButton_CE()
{

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);


    ui->label->setText("0");

}




void MainWindow::clickOnPushButton_isEqualTo()
{
    double answer, termSecond;
    QString labelTerm;

    termSecond = ui->label->text().toDouble();

   if(ui->pushButton_plus->isChecked()){
        answer = termFirst + termSecond;
        labelTerm = QString::number(answer);

        ui->label->setText(labelTerm);
        ui->pushButton_plus->setChecked(false);
   } else if(ui->pushButton_minus->isChecked()){
       answer = termFirst - termSecond;
       labelTerm = QString::number(answer);

       ui->label->setText(labelTerm);
       ui->pushButton_minus->setChecked(false);
   } else if(ui->pushButton_multiply->isChecked()){
       answer = termFirst * termSecond;
       labelTerm = QString::number(answer);

       ui->label->setText(labelTerm);
       ui->pushButton_multiply->setChecked(false);
   } else if(ui->pushButton_divide->isChecked()){
       if (termSecond == 0){
            ui->label->setText("Error");
       } else {
       answer = termFirst / termSecond;
       labelTerm = QString::number(answer);

       ui->label->setText(labelTerm);
       ui->pushButton_divide->setChecked(false);
   }}
}






