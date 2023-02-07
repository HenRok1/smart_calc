#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>


#ifdef __cplusplus
extern "C" {
#endif
#include "../s21_SmartCalc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();

public slots:
    void slot_graph(QString str, int Xmi, int Xma, int Ymi, int Yma);
private:
    Ui::graph *ui;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x,y;

};

#endif // GRAPH_H
