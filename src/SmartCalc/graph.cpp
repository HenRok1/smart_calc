#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
}

graph::~graph()
{
    delete ui;
}

void graph::slot_graph(QString str, int Xmi, int Xma, int Ymi, int Yma)
{
    char *str_expression = (char*)malloc(sizeof(char) * strlen(str.toLocal8Bit().data()));
    strcpy(str_expression, str.toLocal8Bit().data());
    element *elem = NULL;
    int x_found = 0;
    parser(str.toLocal8Bit().data(), &elem, &x_found);
    element *polish_first_elem = NULL;
    double result = 0;
    polish_notation(&elem, &polish_first_elem);
    double xStart = -50, hStart = 0.1, xMin = 0, yMin = 0, xMax = 0, yMax = 0;
    for (X = xStart; X <= 50; X+=hStart) {
        if (calculation(&polish_first_elem, &result, X) == 0) {
          if (xMin > X)
            xMin = X;
          if (yMin > result)
            yMin = result < -200 ? -200 : result;
          if (xMax < X)
            xMax = X;
          if (yMax < result)
            yMax = result > 200 ? 200 : result;;
        }
    }
    if (Xmi < Xma) {
      xMin = Xmi;
      xMax = Xma;
    }
    if (Ymi < Yma) {
      yMin = Ymi;
      yMax = Yma;
    }
    ui->label_expression->setText(str);
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin > -2 ? -3 : yMin, yMax < 2 ? 3 : yMax);
    h = 0.01;
    xBegin = xMin;
    xEnd = xMax + h;
    N = (xEnd - xBegin)/h + 2;
    for (X = xBegin; X <= xEnd; X+=h) {
        if (calculation(&polish_first_elem, &result, X) == 0) {
            if (!(isnan(result) && isinf(result))) {
                x.push_back(X);
                y.push_back(result);
            }
        }
    }
    remove_all_elements(&polish_first_elem);
    free(str_expression);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}
