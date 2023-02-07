#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {
  START_STOP,
  X_t,
  NUM,
  PI = 2,
  MINUS,
  PLUS,
  UNAR_MINUS,
  UNAR_PLUS,
  MUL,
  DIV,
  MOD,
  POW,
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  SIN,
  COS,
  TAN,
  ASIN,
  ACOS,
  ATAN,
  SQRT,
  LN,
  LOG
} type_t;

typedef enum {
  NUM_P = 0,
  MINUS_P = 2,
  PLUS_P = 2,
  UNAR_MINUS_P = 4,
  UNAR_PLUS_P = 4,
  LEFT_PARENTHESIS_P = -1,
  RIGHT_PARENTHESIS_P = -2,
  MUL_P = 3,
  DIV_P = 3,
  MOD_P = 3,
  POW_P = 5,
  SIN_P = 5,
  COS_P = 5,
  TAN_P = 5,
  ASIN_P = 5,
  ACOS_P = 5,
  ATAN_P = 5,
  SQRT_P = 5,
  LN_P = 5,
  LOG_P = 5,
  START_STOP_P = -3
} type_p;

typedef struct tag_element {
  double value;
  type_t opera;
  type_p priority;
  struct tag_element *next;
} element;

int check_numbers(element *first, element *second, element *polish, type_t operat);
void init(element **elem);
int parser(char *expression, element **elem, int *x);
void make_copy(element** first_elem, element **new_elem);
void push(element **elem_last, type_p priority, double val, type_t opera);
void push_start(element **elem_last, type_p priority, double val, type_t opera);
int polish_notation(element **first_elem, element **polish);
int calculation(element** polish_first_elem, double *result, double x);
void remove_all_elements(element **elem);
void remove_element(element **elem);
void remove_middle_element(element **elem, element **previous_elem);
void print_expression(element **first_elem);
void next(element** elem);

#endif //  SRC_S21_SMARTCALC_H_
