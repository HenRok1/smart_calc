#ifndef SRC_S21_BONUSPART_H_
#define SRC_S21_BONUSPART_H_
#include <stdio.h>
#include <math.h>

void payment(double sum, int time, double percent, int *mod, double *payment_mouth, double *total_sum, double *overpay);
double deposit(double sum, double percent, double k);
int time_to_mod(int mod, int time);
int day_in_mouth(int x);

#endif  //  SRC_S21_BONUSPART_H_
