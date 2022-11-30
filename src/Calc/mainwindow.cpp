#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_unar_min, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_step, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ravno, SIGNAL(clicked()), this, SLOT(operations()));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow :: digits_numbers() {
    QPushButton *button = static_cast<QPushButton*>(sender());
    double all_numbers;
    QString new_label;
    all_numbers = (ui->result_show->text()+ button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);
}

//void MainWindow :: operations() {
//    QPushButton *button = static_cast<QPushButton*>(sender());
//    double all_numbers;
//    QString new_label;
//    if (button->text() == "+/-") {
//        all_numbers = (ui->result_show->text()).toDouble();
//        all_numbers *= -1;
//        new_label = QString::number(all_numbers, 'g', 15);
//        ui->result_show->setText(new_label);
//    } else if (button->text() == "%") {
//        all_numbers = (ui->result_show->text()).toDouble();
//        all_numbers *= -1;
//        new_label = QString::number(all_numbers, 'g', 15);
//        ui->result_show->setText(new_label);
//    }
//}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    new_label = ui->result_show->text();

    if (button->text() == "÷" && !(ui->result_show->text().endsWith("÷")) && !(ui->result_show->text().endsWith("/"))) {
        new_label += "/";
    } else if (button->text() == "X" && !(ui->result_show->text().endsWith("X")) && !(ui->result_show->text().endsWith("X"))) {
        new_label += "*";
    } else if (button->text() == "+" && !(ui->result_show->text().endsWith("+"))) {
        new_label += "+";
    } else if (button->text() == "-" && !(ui->result_show->text().endsWith("-"))) {
        new_label += "-";
    } else if (button->text() == "^" && !(ui->result_show->text().endsWith("^"))) {
        new_label += "^";
    } else if (button->text() == "=" && !(ui->result_show->text().endsWith("="))) {
        new_label += "=";
    }


    ui->result_show->setText(new_label);
}



void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->result_show->text().contains("."))
        ui->result_show->setText(ui->result_show->text() + ".");
}


