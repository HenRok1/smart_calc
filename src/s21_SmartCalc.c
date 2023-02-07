#include "s21_SmartCalc.h"

void init(element **elem) {
  (*elem) = (element *)malloc(sizeof(element));
  (*elem)->opera = START_STOP;
  (*elem)->value = 0.0;
  (*elem)->priority = START_STOP_P;
  (*elem)->next = NULL;
}

int parser(char *expression, element **first_elem, int *x) {
  init(first_elem);
  element *elem = *first_elem;
  char *string_number = "0123456789.";
  int error_mark = 0;
  for (; *expression; expression++) {
    if (strchr(string_number, *expression)) {
      char buffer[256] = {'\0'};
      int i = 0;
      for (; *expression && strchr(string_number, *expression); expression++) {
        buffer[i] = *expression;
        i++;
      }
      expression--;
      push(&elem, NUM_P, atof(buffer), NUM);
    } else if (*expression == 'x' || *expression == 'X') {
      push(&elem, NUM_P, 0.0, X_t);
      *x = 1;
    } else if (*expression == '+') {
      push(&elem, PLUS_P, 0.0, PLUS);
    } else if (*expression == '-') {
      push(&elem, MINUS_P, 0.0, MINUS);
    } else if (*expression == '(') {
      push(&elem, LEFT_PARENTHESIS_P, 0.0, LEFT_PARENTHESIS);
    } else if (*expression == ')') {
      push(&elem, RIGHT_PARENTHESIS_P, 0.0, RIGHT_PARENTHESIS);
    } else if (*expression == '*') {
      push(&elem, MUL_P, 0.0, MUL);
    } else if (*expression == '/') {
      push(&elem, DIV_P, 0.0, DIV);
    } else if (*expression == '^') {
      push(&elem, POW_P, 0.0, POW);
    } else if (*expression == 's') {
      expression++;
      if (*expression == 'i') {
        push(&elem, SIN_P, 0.0, SIN);
        expression++;
      } else if (*expression == 'q') {
        push(&elem, SQRT_P, 0.0, SQRT);
        expression += 2;
      } else
        error_mark++;
    } else if (*expression == 'c') {
      expression++;
      if (*expression == 'o') {
        push(&elem, COS_P, 0.0, COS);
        expression++;
      } else
        error_mark++;
    } else if (*expression == 'a') {
      expression++;
      if (*expression == 's') {
        push(&elem, ASIN_P, 0.0, ASIN);
      } else if (*expression == 'c') {
        push(&elem, ACOS_P, 0.0, ACOS);
      } else if (*expression == 't') {
        push(&elem, ATAN_P, 0.0, ATAN);
      } else
        error_mark++;
      expression += 2;
    } else if (*expression == 't') {
      expression++;
      if (*expression == 'a') {
        push(&elem, TAN_P, 0.0, TAN);
      } else
        error_mark++;
      expression++;
    } else if (*expression == 'm') {
      expression++;
      if (*expression == 'o') {
        push(&elem, MOD_P, 0.0, MOD);
      } else
        error_mark++;
      expression++;
    } else if (*expression == 'l') {
      expression++;
      if (*expression == 'n') {
        push(&elem, LN_P, 0.0, LN);
      } else if (*expression == 'o') {
        push(&elem, LOG_P, 0.0, LOG);
        expression++;
      } else
        error_mark++;
    } else if (*expression == 'p' || *expression == 'P') {
      expression++;
      if (*expression == 'i' || *expression == 'I') {
        push(&elem, NUM_P, M_PI, PI);
      } else
        error_mark++;
    }
  }
  push(&elem, START_STOP_P, 0.0, START_STOP);
  return error_mark;
}

int polish_notation(element **first_elem, element **polish_first_elem) {
  int error_mark = 0;
  element *elem = *first_elem;
  init(polish_first_elem);
  element *polish = *polish_first_elem;
  element *stack = NULL;
  init(&stack);
  next(&elem);
  if (elem->opera == RIGHT_PARENTHESIS) error_mark++;
  type_t lastOpera = LEFT_PARENTHESIS;
  for (int i = 0; elem != NULL && !error_mark; next(&elem), i++) {
    if (elem->opera == NUM || elem->opera == X_t) {
      push(&polish, elem->priority, elem->value, elem->opera);
    } else if (elem->opera == LEFT_PARENTHESIS) {
      push_start(&stack, elem->priority, elem->value, elem->opera);
    } else if (elem->opera == RIGHT_PARENTHESIS) {
      for (; stack->opera != LEFT_PARENTHESIS;) {
        if (stack->opera == START_STOP) {
          error_mark++;
          break;
        }

        push(&polish, stack->priority, stack->value, stack->opera);
        remove_element(&stack);
      }
      remove_element(&stack);
    } else if (elem->priority > NUM_P && elem->priority < 10) {
      if (elem->opera == MINUS &&
          (i == 0 || (lastOpera >= MINUS && lastOpera <= LEFT_PARENTHESIS))) {
        elem->opera = UNAR_MINUS;
        elem->priority = UNAR_MINUS_P;
      } else if (elem->opera == PLUS &&
                 (i == 0 ||
                  (lastOpera >= MINUS && lastOpera <= LEFT_PARENTHESIS))) {
        elem->opera = UNAR_PLUS;
        elem->priority = UNAR_PLUS_P;
      }
      while (stack->opera > START_STOP && stack->priority >= elem->priority) {
        push(&polish, stack->priority, stack->value, stack->opera);
        remove_element(&stack);
      }
      push_start(&stack, elem->priority, elem->value, elem->opera);
    }
    lastOpera = elem->opera;
  }
  if (stack != NULL) {
    for (; stack->opera != START_STOP && stack->next != NULL && !error_mark;) {
      if (stack->opera == LEFT_PARENTHESIS) {
        error_mark++;
        break;
      }
      push(&polish, stack->priority, stack->value, stack->opera);
      remove_element(&stack);
    }
    remove_all_elements(&stack);
  } else
    error_mark++;

  push(&polish, START_STOP_P, 0.0, START_STOP);
  // print_expression(polish_first_elem);
  remove_all_elements(first_elem);
  return error_mark;
}

int calculation(element **polish_first_elem, double *result, double x) {
  element *polish_first_elem_copy = NULL;
  make_copy(polish_first_elem, &polish_first_elem_copy);
  element *polish = polish_first_elem_copy;
  element *first = polish_first_elem_copy;
  element *second = polish_first_elem_copy;
  int error_mark = 0;
  next(&polish);
  for (; polish->next != NULL;) {
    if (polish->opera == START_STOP) {
      next(&polish);
    } else if (polish->opera == NUM || polish->opera == X_t) {
      if ((polish->opera == NUM || polish->opera == X_t) &&
          (polish->next->opera == NUM || polish->next->opera == X_t)) {
        if (polish->opera == X_t) {
          polish->value = x;
          polish->opera = NUM;
        }
        first = polish;
      }
      if (polish->next->opera != NUM &&
          (polish->opera == NUM || polish->opera == X_t)) {
        if (polish->opera == X_t) {
          polish->value = x;
          polish->opera = NUM;
        }
        second = polish;
      }
      next(&polish);
    } else if (check_numbers(first, second, polish, PLUS)) {
      first->value = first->value + second->value;
      remove_middle_element(&polish, &second);
      remove_middle_element(&second, &first);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, MINUS)) {
      first->value = first->value - second->value;
      remove_middle_element(&polish, &second);
      remove_middle_element(&second, &first);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, MUL)) {
      first->value = first->value * second->value;
      remove_middle_element(&polish, &second);
      remove_middle_element(&second, &first);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, DIV)) {
      if (second->value != 0) {
        first->value = first->value / second->value;
        remove_middle_element(&polish, &second);
        remove_middle_element(&second, &first);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 1;
        break;
      }
    } else if (check_numbers(first, second, polish, POW)) {
      first->value = pow(first->value, second->value);
      remove_middle_element(&polish, &second);
      remove_middle_element(&second, &first);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, MOD)) {
      if (second->value != 0 && (int)(second->value) == second->value &&
          (int)(first->value) == first->value) {
        first->value = (int)first->value % (int)second->value;
        remove_middle_element(&polish, &second);
        remove_middle_element(&second, &first);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 1;
        break;
      }
    } else if (check_numbers(first, second, polish, SIN)) {
      second->value = sin(second->value);
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, UNAR_MINUS)) {
      second->value = second->value * (-1);
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, UNAR_PLUS)) {
      ;
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, COS)) {
      second->value = cos(second->value);
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, TAN)) {
      second->value = tan(second->value);
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, ASIN)) {
      if (second->value >= -1 && second->value <= 1) {
        second->value = asin(second->value);
        remove_middle_element(&polish, &second);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 2;
        break;
      }
    } else if (check_numbers(first, second, polish, ACOS)) {
      if (second->value >= -1 && second->value <= 1) {
        second->value = acos(second->value);
        remove_middle_element(&polish, &second);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 2;
        break;
      }
    } else if (check_numbers(first, second, polish, ATAN)) {
      second->value = atan(second->value);
      remove_middle_element(&polish, &second);
      polish = polish_first_elem_copy;
    } else if (check_numbers(first, second, polish, SQRT)) {
      if (second->value >= 0) {
        second->value = sqrt(second->value);
        remove_middle_element(&polish, &second);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 2;
        break;
      }
    } else if (check_numbers(first, second, polish, LN)) {
      if (second->value > 0) {
        second->value = log(second->value);
        remove_middle_element(&polish, &second);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 2;
        break;
      }
    } else if (check_numbers(first, second, polish, LOG)) {
      if (second->value > 0) {
        second->value = log10(second->value);
        remove_middle_element(&polish, &second);
        polish = polish_first_elem_copy;
      } else {
        error_mark = 2;
        break;
      }
    } else {
      error_mark = 4;
      break;
    }
  }
  polish = polish_first_elem_copy;
  next(&polish);
  *result = polish->value;
  remove_all_elements(&polish_first_elem_copy);
  return error_mark;
}

int check_numbers(element *first, element *second, element *polish,
                  type_t operat) {
  return (first->opera != START_STOP || second->opera != START_STOP) &&
         polish->opera == operat;
}

void next(element **elem) { *elem = (*elem)->next; }

void make_copy(element **first_elem, element **new_elem) {
  element *new_elem_tik = NULL;
  element *elem = *first_elem;
  init(&new_elem_tik);
  *new_elem = new_elem_tik;
  next(&elem);
  while (elem != NULL) {
    push(&new_elem_tik, elem->priority, elem->value, elem->opera);
    next(&elem);
  }
}

void push(element **elem_last, type_p priority, double val, type_t opera) {
  element *elem;
  if ((elem = (element *)malloc(sizeof(element))) != NULL) {
    elem->opera = opera;
    elem->value = val;
    elem->priority = priority;
    elem->next = NULL;
    (*elem_last)->next = elem;
    (*elem_last) = elem;
  }
}
void push_start(element **first_elem, type_p priority, double val,
                type_t opera) {
  element *elem;
  if ((elem = (element *)malloc(sizeof(element))) != NULL) {
    elem->opera = opera;
    elem->value = val;
    elem->priority = priority;
    elem->next = *first_elem;
    *first_elem = elem;
  }
}

void remove_all_elements(element **elem) {
  do {
    remove_element(elem);
  } while (*elem != NULL);
}

void remove_element(element **elem) {
  element *elem_next = (*elem)->next == NULL ? NULL : (*elem)->next;
  if (*elem) free(*elem);
  *elem = elem_next;
}

void remove_middle_element(element **elem, element **previous_elem) {
  remove_element(elem);
  (*previous_elem)->next = *elem;
}

void print_expression(element **first_elem) {
  element *elem = *(first_elem);
  do {
    if (elem->priority != NUM_P)
      printf(" %d", elem->opera);
    else
      printf(" =%.0lf", elem->value);
    if (elem->next != NULL) elem = elem->next;
  } while (elem->next != NULL || elem == NULL);
  printf("\n");
}

// int main() {
//   element* elem = NULL;
//   element* polish = NULL;
//   int x = 0;
//   double x_res = 0;
//   printf("parsing: %d\n", parser("asin(x)", &elem, &x));
//   printf("polish: %d\n", polish_notation(&elem, &polish));
//   printf("calcul: %d\n", calculation(&polish, &x_res, 1));
//   printf("Otvet: %lf\n", x_res);
//   remove_all_elements(&polish);
//   return 0;
// }
