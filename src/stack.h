#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  num = 1,
  x,
  plus,
  minus,
  mult,
  del,
  stepen,
  mod,
  skobka_o,
  skobka_c,
  unar_plus,
  unar_minus,
  cosine,
  sine,
  tangent,
  acosine,
  asine,
  atangent,
  sqrt_t,
  ln_t,
  log_t,  //десятичный лог
} oper;

typedef struct Node {
  double value;
  int prior;
  oper type;
  struct Node* next;
} stack;

void push(stack** head, double value, int type, int prior);
stack pop(stack** head);
void destroy(stack** head);
stack top(stack** head);
int topSimType(stack** head);

stack read_lines(char* stack, int* iter);
int change_prior(char* str);
stack calc_two_args(int type, double num1, double num2);
stack calc_one_arg(double num, int type);
double read_str(char* str, double x);
stack read_num(const char* str, int* j);
void vichislenie(stack** stackNum, stack** stackSim);
void main_log(stack** stackNum, stack** stackSim, stack this, double x_num);
int check_for_er(char* str);