#include "s21_bonusPart.h"

void payment(double sum, int time, double percent, int *mod,
             double *payment_mouth, double *total_sum, double *overpay) {
  *total_sum = 0;
  *overpay = 0;
  *payment_mouth = 0;
  if (*mod == 0) {
    // double payment_mouth = 0;
    *payment_mouth = sum * percent / (100 * 12) /
                     (1 - pow(1 + percent / (100 * 12), (-1) * time));
    *total_sum = *payment_mouth * time;
    *overpay = *total_sum - sum;
  } else if (*mod >= 1) {
    double pay = sum / time;
    double s = sum;
    for (int i = 1; i <= time; i++) {
      if (i == *mod) *payment_mouth = pay + sum * percent * 31 / (100 * 365);
      (*total_sum) += (pay + sum * percent / 100 * 30 / 365);
      sum -= (int)pay;
    }
    *overpay = *total_sum - s;
  }
}

double deposit(double sum, double percent, double k) {
  return sum * percent / 100 / k;
}

int time_to_mod(int mod, int time) {
  double result = 0;
  if (mod == 1) {
    result = time / 12 * 365;
  } else if (mod == 2) {
    result = time / 12 * 365 / 7;
  } else if (mod == 3) {
    result = time;
  } else if (mod == 4) {
    result = time / 4;
  } else if (mod == 5) {
    result = time / 6;
  } else if (mod == 6) {
    result = time / 12;
  } else if (mod == 7) {
    result = 1;
  }
  return (int)result;
}
int day_in_mouth(int x) {
  return 28 + (x + (int)floor(x / 8)) % 2 + 2 % x + 2 * (int)floor(1 / x);
}
// int main() {
//   double payment_mouth = 0, total_sum = 0, overpay = 0;
//   int may = 1;
//   payment(300000, 6, 20, &may, &payment_mouth, &total_sum, &overpay);
//   printf("In mouth: %lf\nTotal: %lf\nOverpay: %lf\n", payment_mouth,
//   total_sum,
//          overpay);
// }
