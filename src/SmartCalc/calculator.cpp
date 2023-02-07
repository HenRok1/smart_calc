#include "calculator.h"
#include "./ui_calculator.h"
#include <QMessageBox>



Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->dtEdit_dep_create->setMinimumDate(QDate::currentDate());
    ui->dtEdit_dep_add->setMinimumDate(QDate::currentDate().addDays(2));
    ui->btn_dep_add->setEnabled(false);

    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnPi, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnSin, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnCos, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnTan, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnAsin, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnAcos, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnAtan, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnLn, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnLog, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnLeftParenthesis, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnRightParenthesis, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnMod, SIGNAL(clicked()), this, SLOT(make_expression_func()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnMul, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnDiv, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnPow, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnX, SIGNAL(clicked()), this, SLOT(make_expression()));
    connect(ui->btnPoint, SIGNAL(clicked()), this, SLOT(make_expression()));
}

Calculator::~Calculator()
{
    this->clearTable();
    delete ui;
}

void Calculator::check_start_expression() {
    if (ui->text_expression->text() == '0') {
        ui->text_expression->setText("");
    }
}

void Calculator::make_expression() {
    check_start_expression();
    QPushButton *btn = (QPushButton*) sender();
    ui->text_expression->setText(ui->text_expression->text() + btn->text());
}

void Calculator::make_expression_func() {
    check_start_expression();
    QPushButton *btn = (QPushButton*) sender();
    ui->text_expression->setText(ui->text_expression->text() + btn->text() + '(');
}

void Calculator::on_btnDelete_clicked()
{
    ui->text_expression->setText("0");
}


void Calculator::on_btnSign_clicked() {
    check_start_expression();

    ui->text_expression->setText(ui->text_expression->text() + "(-");
}

void Calculator:: ()
{
     element *elem = NULL;
     char *str_expression = (char*)malloc(sizeof(char) * strlen(ui->text_expression->text().toLocal8Bit().data()));
     strcpy( str_expression, ui->text_expression->text().toLocal8Bit().data());
     int x_found = 0;
     if (parser(str_expression, &elem, &x_found) == 0) {
         element *polish_first_elem = NULL;
         if (polish_notation(&elem, &polish_first_elem) == 0) {
         if (x_found == 1)  {
            window_graph = new graph(this);
            window_graph->show();
            remove_all_elements(&polish_first_elem);
            free(str_expression);
            connect(this, &Calculator::signal_expression, window_graph, &graph::slot_graph);
            emit signal_expression(ui->text_expression->text(), ui->spnBx_Xmin->value(), ui->spnBx_Xmax->value(), ui->spnBx_Ymin->value(), ui->spnBx_Ymax->value());
         } else {
             double result = 0;
             calculation(&polish_first_elem, &result, 0);
             remove_all_elements(&polish_first_elem);
             QString str_result = QString::number(result);
             ui->text_expression->setText(str_result);
         }
         } else
             QMessageBox::critical(this,"Ошибка", "Некорректное выражение(2lvl): "+ui->text_expression->text());
     } else {
         QMessageBox::critical(this,"Ошибка", "Некорректное выражение: "+ui->text_expression->text());
     }
}


void Calculator::on_rdBtn_diff_clicked(bool checked)
{
    if (checked) {
        ui->textEdit->clear();
        ui->lnEdit_Payment->setEnabled(false);
        ui->textEdit->setEnabled(true);

        double i_sum = ui->lnEdit_sum->text().toDouble();
        int time = ui->spnBx_date->value();
        double percent = ui->dblSpnBx_percent->value();
        double payment_mouth = 0, total_sum = 0, overpay = 0;
        for (int i = 1; i <= time; i++) {
            int mod = i;
            payment(i_sum, time, percent, &mod, &payment_mouth, &total_sum, &overpay);
            ui->textEdit->append(QString::number(mod)+") "+QString::number(payment_mouth));
        }

        ui->lnEdit_Overpayment->setText(QString::number(overpay));
        ui->lnEdit_Fullpayment->setText(QString::number(total_sum));
    }
}


void Calculator::on_rdBtn_annuit_clicked(bool checked)
{
    if (checked) {
        ui->lnEdit_Payment->setEnabled(true);
        ui->textEdit->setEnabled(false);

        int mod = 0;
        double i_sum = ui->lnEdit_sum->text().toDouble();
        int time = ui->spnBx_date->value();
        double percent = ui->dblSpnBx_percent->value();
        double payment_mouth = 0, total_sum = 0, overpay = 0;

        payment(i_sum, time, percent, &mod, &payment_mouth, &total_sum, &overpay);

        ui->lnEdit_Overpayment->setText(QString::number(overpay));
        ui->lnEdit_Fullpayment->setText(QString::number(total_sum));
        ui->lnEdit_Payment->setText(QString::number(payment_mouth));
    }
}

double Calculator::count_of_deposit(int mod, QDate *date) {
    int daysInDeposit = date->daysTo(date->addMonths(ui->spnBx_dep_date->value()));
    int result = 0;
    if (mod == 1) {
        result = date->daysInYear();
    } else if (mod == 2) {
        result = (int)(date->daysInYear() / 7);
    } else if (mod == 3) {
        result = 12;
    } else if (mod == 4) {
        result = 4;
    } else if (mod == 5) {
        result = 2;
    } else if (mod == 6) {
        result = 1;
    } else if (mod == 7) {
        result = 0;
    }
    return daysInDeposit * result / date->daysInYear();
}

void Calculator::count_of_days(int mod, QDate *date) {
      if (mod == 1) {
        *date = date->addDays(1);
      } else if (mod == 2) {
        *date = date->addDays(7);
      } else if (mod == 3) {
        *date = date->addMonths(1);
      } else if (mod == 4) {
        *date = date->addMonths(4);
      } else if (mod == 5) {
        *date = date->addMonths(6);
      } else if (mod == 6) {
        *date = date->addYears(1);
      } else if (mod == 7 && *date != ui->dtEdit_dep_add->date().addMonths(ui->spnBx_dep_date->value()))
          QMessageBox::critical(this,"Ошибка", "Ошибка времени"+ui->text_expression->text());
}

void Calculator::createUI(const QStringList &headers) {
    ui->table_dep->clear();
    ui->table_dep->setColumnCount(5);
    ui->table_dep->setShowGrid(true);
    ui->table_dep->setHorizontalHeaderLabels(headers);
    ui->table_dep->horizontalHeader()->setStretchLastSection(true);
}

void Calculator::clearTable() {
    for (int i = ui->table_dep->rowCount(); i >= 0 ; i--) {
        for (int j = 0; j < 5; j++)
            delete ui->table_dep->item(i, j);
        ui->table_dep->removeRow(i);
    }
}

void Calculator::count_tax() {
  double percent_value = ui->table_dep->item(ui->table_dep->rowCount() - 1, 4)->text().toDouble();
  ui->dep_tax->setText(QString::number(percent_value * (1 - ui->dblspBx_dep_tax->value() / 100))+" Рублей");
}

void Calculator::on_btn_dep_create_clicked()
{
    ui->btn_dep_add->setEnabled(true);
    this->clearTable();
    this->createUI(QStringList() << ("Дата")
                                     << ("Изменения")
                                     << ("Статус")
                                     << ("Остаток вклада")
                                     << ("Проценты")
                   );
    int payment = ui->cmbBx_payment->currentIndex() + 1;
    if (ui->chckBx_capitaliz->checkState())
        payment *= -1;
    QDate date = ui->dtEdit_dep_create->date();
    ui->table_dep->insertRow(0);
    ui->table_dep->setItem(0,0, new QTableWidgetItem(date.toString("dd.MM.yyyy")));
    ui->table_dep->setItem(0,1, new QTableWidgetItem('+'+ui->lnEdit_dep_sum->text()));
    ui->table_dep->setItem(0,2, new QTableWidgetItem("Открытие вклада"));
    ui->table_dep->setItem(0,3, new QTableWidgetItem(ui->lnEdit_dep_sum->text()));
    ui->table_dep->setItem(0,4, new QTableWidgetItem("0"));

    QDate date_now = date;
    double k = 0;
    if (abs(payment) == 7) {
      date_now = date.addMonths(ui->spnBx_dep_date->value());
      k = 1;
    } else
      k = count_of_deposit(abs(payment), &date);

    for (int i = 1; i <= k; i++) {
        ui->table_dep->insertRow(ui->table_dep->rowCount());
        print_in_table(i, payment, &date_now, k);
    }
    count_tax();
}

void Calculator::on_btn_dep_add_clicked()
{
    if (ui->rdBtn_dep_add_minus->isChecked() == false && ui->rdBtn_dep_add_plus->isChecked() == false)
        ui->rdBtn_dep_add_plus->setChecked(true);

    double sum = ui->lnEdit_dep_add->text().toDouble();
    QString sum_text = "пополнение";
    if (ui->rdBtn_dep_add_minus->isChecked() == true) {
        sum *= -1;
        sum_text = "снятие";
    }
    ui->table_dep->insertRow(ui->table_dep->rowCount());
    int index = ui->table_dep->rowCount() - 1;
    for (int i = ui->table_dep->rowCount() - 1; i > 0; i--) {
        if (ui->dtEdit_dep_add->date() < QDate::fromString(ui->table_dep->item(i-1,0)->text(), "dd.MM.yyyy"))
            for (int j = 0; j < ui->table_dep->columnCount(); j++) {
                ui->table_dep->setItem(i, j, new QTableWidgetItem(ui->table_dep->item(i - 1, j)->text()));
                index = i;
            }
        else
            break;
    }

    ui->dtEdit_dep_add->setDate(ui->dtEdit_dep_add->date().addDays(1));

    ui->table_dep->setItem(index, 0, new QTableWidgetItem(ui->dtEdit_dep_add->date().toString("dd.MM.yyyy")));
    ui->table_dep->setItem(index, 1, new QTableWidgetItem(QString::number(sum)));
    ui->table_dep->setItem(index, 2, new QTableWidgetItem("Частичное "+sum_text));
    ui->table_dep->setItem(index, 3, new QTableWidgetItem(QString::number(ui->table_dep->item(index - 1, 3)->text().toDouble() + sum)));
    ui->table_dep->setItem(index, 4, new QTableWidgetItem(ui->table_dep->item(index - 1, 4)->text()));

    int payment = ui->cmbBx_payment->currentIndex() + 1;
    if (ui->chckBx_capitaliz->checkState())
        payment *= -1;

    QDate date_now = QDate::fromString(ui->table_dep->item(index - 1,0)->text(), "dd.MM.yyyy");
    double k = count_of_deposit(abs(payment), &date_now);
    for (int i = index + 1; i <= k + 1; i++)
        print_in_table(i, payment, &date_now, k);
    count_tax();

}

void Calculator::print_in_table(int index_row, double payment, QDate *date_now, double k) {
    double percent = deposit(ui->table_dep->item(index_row - 1, 3)->text().toDouble(), ui->dblspnBx_dep_percent->value(), k);
    count_of_days(abs(payment), date_now);
    ui->table_dep->setItem(index_row,0, new QTableWidgetItem(date_now->toString("dd.MM.yyyy")));
    ui->table_dep->setItem(index_row,1, new QTableWidgetItem('+'+QString::number(percent, 'L', 20)));
    ui->table_dep->setItem(index_row,2, new QTableWidgetItem("Начисление процентов"));
    if (payment < 0)
        ui->table_dep->setItem(index_row,3, new QTableWidgetItem(QString::number(ui->table_dep->item(index_row - 1, 3)->text().toDouble() + percent)));
    else
        ui->table_dep->setItem(index_row,3, new QTableWidgetItem(QString::number(ui->table_dep->item(index_row - 1, 3)->text().toDouble())));
    ui->table_dep->setItem(index_row,4, new QTableWidgetItem(QString::number(ui->table_dep->item(index_row - 1, 4)->text().toDouble() + percent)));
}
