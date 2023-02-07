#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <graph.h>
#include <cstdlib>

#ifdef __cplusplus
extern "C" {
#endif
    #include "../s21_SmartCalc.h"
    #include "../s21_bonusPart.h"
#ifdef __cplusplus
}
#endif



QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();


private slots:
    void make_expression();
    void make_expression_func();
    void check_start_expression();
    void createUI(const QStringList &headers);
    void clearTable();
    double count_of_deposit(int mod,  QDate *date);
    void count_of_days(int mod, QDate *date);
    void print_in_table(int index_row, double payment, QDate *date_now, double k);
    void count_tax();

    void on_btnDelete_clicked();

    void on_btnSign_clicked();

    void on_btnResult_clicked();

    void on_rdBtn_diff_clicked(bool checked);

    void on_rdBtn_annuit_clicked(bool checked);

    void on_btn_dep_create_clicked();

    void on_btn_dep_add_clicked();

signals:
    void signal_expression(QString str, int Xmi, int Xma, int Ymi, int Yma);

private:
    Ui::Calculator *ui;
    graph *window_graph;
};
#endif // CALCULATOR_H
