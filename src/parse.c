// #include "parse.h"
#include "stack.h"

stack read_lines(char *str, int *iter) {
  stack result = {0};
  int i = *iter;
  if (str[i] == 'x' || str[i] == 'X') {
    result.type = x;
    result.prior = 1;
    result.value = 0;
    i++;
  } else if (str[i] == '+') {
    result.type = plus;
    result.prior = 2;
    result.value = 0;
    i++;
  } else if (str[i] == '-') {
    result.type = minus;
    result.prior = 2;
    result.value = 0;
    i++;
  } else if (str[i] == '*') {
    result.type = mult;
    result.prior = 3;
    result.value = 0;
    i++;
  } else if (str[i] == '/') {
    result.type = del;
    result.prior = 3;
    result.value = 0;
    i++;
  } else if (str[i] == '^') {
    result.type = stepen;
    result.prior = 4;
    result.value = 0;
    i++;
  } else if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') {
    result.type = mod;
    result.prior = 3;
    result.value = 0;
    i += 3;
  } else if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
    result.type = cosine;
    result.prior = 5;
    result.value = 0;
    i += 3;
  } else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') {
    result.type = sine;
    result.prior = 5;
    result.value = 0;
    i += 3;
  } else if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') {
    result.type = tangent;
    result.prior = 5;
    result.value = 0;
    i += 3;
  } else if (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o' &&
             str[i + 3] == 's') {
    result.type = acosine;
    result.prior = 5;
    result.value = 0;
    i += 4;
  } else if (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i' &&
             str[i + 3] == 'n') {
    result.type = asine;
    result.prior = 5;
    result.value = 0;
    i += 4;
  } else if (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a' &&
             str[i + 3] == 'n') {
    result.type = atangent;
    result.prior = 5;
    result.value = 0;
    i += 4;
  } else if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
             str[i + 3] == 't') {
    result.type = sqrt_t;
    result.prior = 4;
    result.value = 0;
    i += 4;
  } else if (str[i] == 'l' && str[i + 1] == 'n') {
    result.type = ln_t;
    result.prior = 5;
    result.value = 0;
    i += 2;
  } else if (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'g') {
    result.type = log_t;
    result.prior = 5;
    result.value = 0;
    i += 3;
  } else if (str[i] == '(') {
    result.type = skobka_o;
    result.prior = -1;
    result.value = 0;
    i++;
  } else if (str[i] == ')') {
    result.type = skobka_c;
    result.prior = -1;
    result.value = 0;
    i++;
  }
  *iter = i;

  return result;
}

stack calc_two_args(int type, double num1, double num2) {
  stack result;
  result.prior = 0;
  result.type = num;
  if (type == plus) {
    result.value = num1 + num2;
  } else if (type == minus) {
    result.value = num1 - num2;
  } else if (type == del) {
    result.value = num1 / num2;
  } else if (type == mult) {
    result.value = num1 * num2;
  } else if (type == stepen) {
    result.value = pow(num1, num2);
  } else if (type == mod) {
    result.value = fmod(num1, num2);
  }
  return result;
}

stack calc_one_arg(double num, int type) {
  stack result;
  result.prior = 0;
  result.type = num;
  if (type == cosine) {
    result.value = cos(num);
  } else if (type == sine) {
    result.value = sin(num);
  } else if (type == tangent) {
    result.value = tan(num);
  } else if (type == asine) {
    result.value = asin(num);
  } else if (type == acosine) {
    result.value = acos(num);
  } else if (type == atangent) {
    result.value = atan(num);
  } else if (type == sqrt_t) {
    result.value = sqrt(num);
  } else if (type == ln_t) {
    result.value = log(num);
  } else if (type == log_t) {
    result.value = log10(num);
  }
  return result;
}

double read_str(char *str, double x) {
  stack *stackNum = NULL;
  stack *stackSim = NULL;
  int i = 0;
  if (str[0] == '+' || str[0] == '-') {
    push(&stackNum, 0, num, 0);
  }
  int length = strlen(str);
  while (i < length) {
    if (*(str + i) == ' ') {
      i++;
    }
    if ((*(str + i) >= '0' && (*(str + i) < '9')) || (*(str + i) == '.')) {
      stack num1 = read_num(str, &i);
      push(&stackNum, num1.value, num, 0);
    } else {
      stack tmp = read_lines(str, &i);
      if (i > 1 && *(str + i - 2) == '(' &&
          (tmp.type == plus || tmp.type == minus)) {
        push(&stackNum, 0, num, 0);
      }
      main_log(&stackNum, &stackSim, tmp, x);
      // i++;
    }
  }
  while (stackSim != NULL && stackNum != NULL) {
    vichislenie(&stackNum, &stackSim);
  }
  stack result = top(&stackNum);
  double resultt = result.value;
  pop(&stackNum);
  return resultt;
}

stack read_num(const char *str, int *j) {
  stack result = {0};
  int count = 1, flag = 0;
  int i = *j;
  for (; i < (int)strlen(str) &&
         ((str[i] >= 48 && str[i] <= 57) || (str[i] == 46));
       i++) {
    result.type = num;
    if (str[i] == 46) {
      flag = 1;
      count = 10;
      i++;
    }
    if (flag) {
      int temp = str[i] - '0';
      double temp2 = (double)temp / count;
      result.value = result.value + temp2;
      count *= 10;
    } else {
      result.value = result.value * count;
      result.value = result.value + str[i] - '0';
      count = 10;
    }
    result.prior = 0;
  }
  *j = i;
  return result;
}

void vichislenie(stack **stackNum, stack **stackSim) {
  stack operator= pop(stackSim);
  stack val1;
  stack val2;
  stack result;
  if (operator.type> 8) {
    val2 = pop(stackNum);
  } else {
    val1 = pop(stackNum);
    val2 = pop(stackNum);
  }
  if (operator.type <= 8) {
    result = calc_two_args(operator.type, val2.value, val1.value);
  } else {
    result = calc_one_arg(val2.value, operator.type);
  }
  push(stackNum, result.value, result.type, result.prior);
}

void main_log(stack **stackNum, stack **stackSim, stack this, double x_num) {
  stack topStack;

  if (*stackSim != NULL) {
    topStack = top(stackSim);
  } else {
    topStack.prior = -1;
  }
  if (this.type == x) {
    push(stackNum, x_num, num, 1);
  } else if (this.type == skobka_o) {
    push(stackSim, 0, skobka_o, -1);
  } else if (this.prior > topStack.prior && this.type != skobka_c) {
    push(stackSim, 0, this.type, this.prior);
  } else if (this.prior <= topStack.prior && this.type != skobka_c &&
             this.type != skobka_o) {
    vichislenie(stackNum, stackSim);
    push(stackSim, this.value, this.type, this.prior);
  } else if (this.type == skobka_c) {
    while (stackSim && topSimType(stackSim) != skobka_o) {
      vichislenie(stackNum, stackSim);
    }
    pop(stackSim);
  }
}

int check_for_er(char *str) {
  int result = 1, count = 1, scob = 0;
  while (count != (int)strlen(str)) {
    if (str[count] == 'x' && count != 0 && count != (int)strlen(str)) {
      if (str[count - 1] == ')' || str[count + 1] == '(' ||
          (str[count - 1] <= '9' && str[count - 1] >= '0') ||
          (str[count + 1] <= '9' && str[count + 1] >= '0') ||
          str[count + 1] == 's' || str[count + 1] == 'c' ||
          str[count + 1] == 't' || str[count + 1] == 'a' ||
          str[count + 1] == 'l' || str[count + 1] == 'm' ||
          str[count + 1] == 'i' || str[count + 1] == 'o' ||
          str[count + 1] == 'q' || str[count + 1] == 'n') {
        result = 0;
      }
    }
    if (str[count] == '.') {
      if (count == 0 || count == (int)strlen(str) - 1) {
        result = 0;
      } else {
        if ((str[count - 1] >= '9' && str[count - 1] <= '0') ||
            (str[count + 1] >= '9' && str[count + 1] <= '0')) {
          result = 0;
        }
      }
    } else if (str[count] == '+' || str[count] == '-' || str[count] == '*' ||
               str[count] == '/' || str[count] == '^') {
      if (count == 0) {
        if (str[count] != '-') {
          result = 0;
        } else if (str[count] == '-' && str[count + 1] <= '0' &&
                   str[count + 1] >= '9') {
          result = 0;
        } else if (count == (int)strlen(str) - 1) {
          result = 0;
        } else {
          if ((str[count - 1] != ')' && str[count - 1] > '9' &&
               str[count - 1] < '0') ||
              (str[count + 1] < '0' && str[count + 1] > '9') ||
              str[count + 1] == 'm' || str[count + 1] == '+' ||
              str[count + 1] == '-' || str[count + 1] == '*' ||
              str[count + 1] == '/' || str[count + 1] == '^') {
            result = 0;
          }
        }
      }
    } else if (str[count] == ')') {
      scob -= 1;
      if (scob == -1) {
        result = 0;
      }
      if (count != 0) {
        if (str[count - 1] == '+' || str[count - 1] == '/' ||
            str[count - 1] == '*' || str[count - 1] == '-' ||
            str[count - 1] == '^' || str[count - 1] == '(') {
          result = 0;
        }
        if ((str[count + 1] == 's' && str[count + 2] == 'i' &&
             str[count + 3] == 'n') ||
            (str[count + 1] == 'c' && str[count + 2] == 'o' &&
             str[count + 3] == 's') ||
            (str[count + 1] == 't' && str[count + 2] == 'a' &&
             str[count + 3] == 'n') ||
            (str[count + 1] == 'a' && str[count + 2] == 's' &&
             str[count + 3] == 'i' && str[count + 4] == 'n') ||
            (str[count + 1] == 'a' && str[count + 2] == 'c' &&
             str[count + 3] == 'o' && str[count + 4] == 's') ||
            (str[count + 1] == 'l' && str[count + 2] == 'n') ||
            (str[count + 1] == 'l' && str[count + 2] == 'o' &&
             str[count + 3] == 'g') ||
            (str[count + 1] == 'a' && str[count + 2] == 't' &&
             str[count + 3] == 'a' && str[count + 4] == 'n') ||
            (str[count + 1] == 's' && str[count + 2] == 'q' &&
             str[count + 3] == 'r' && str[count + 4] == 't') ||
            (str[count + 1] == 'm' && str[count + 2] == 'o' &&
             str[count + 3] == 'd')) {
          result = 0;
        }
      } else {
        result = 0;
      }
    } else if (str[count] == '(') {
      scob += 1;
      if (count != (int)strlen(str) - 1) {
        if (str[count + 1] == '+' || str[count + 1] == '/' ||
            str[count + 1] == '*' || str[count + 1] == '^' ||
            str[count + 1] == ')') {
          result = 0;
        }
        if (str[count - 1] <= '9' && str[count - 1] >= '0') {
          result = 0;
        }
      } else {
        result = 0;
      }
    } else if (((str[count] == 's' && str[count + 1] == 'i' &&
                 str[count + 2] == 'n') ||
                (str[count] == 'c' && str[count + 1] == 'o' &&
                 str[count + 2] == 's') ||
                (str[count] == 't' && str[count + 1] == 'a' &&
                 str[count + 2] == 'n') ||
                (str[count] == 'a' && str[count + 1] == 's' &&
                 str[count + 2] == 'i' && str[count + 3] == 'n') ||
                (str[count] == 'a' && str[count + 1] == 'c' &&
                 str[count + 2] == 'o' && str[count + 3] == 's') ||
                (str[count] == 'l' && str[count + 1] == 'n') ||
                (str[count] == 'l' && str[count + 1] == 'o' &&
                 str[count + 2] == 'g') ||
                (str[count] == 'a' && str[count + 1] == 't' &&
                 str[count + 2] == 'a' && str[count + 3] == 'n') ||
                (str[count] == 's' && str[count + 1] == 'q' &&
                 str[count + 2] == 'r' && str[count + 3] == 't'))) {
      if ((count != 0 && str[count - 1] == ')') ||
          (str[count - 1] <= '9' && str[count - 1] >= '0')) {
        result = 0;
      }
    } else if (str[count] == 'm' && str[count + 1] == 'o' &&
               str[count + 2] == 'd') {
      if ((count == 0 && str[count] == 'm') ||
          (str[count] == 'd' && count == (int)strlen(str) - 1)) {
        result = 0;
      } else if (count != 0 && str[count] == 'm' &&
                 (str[count - 1] == '(' || str[count - 1] == '+' ||
                  str[count - 1] == '/' || str[count - 1] == '*' ||
                  str[count - 1] == '-' || str[count - 1] == '^')) {
        result = 0;
      } else if (count != (int)strlen(str) - 1 && str[count] == 'd' &&
                 (str[count + 1] == '+' || str[count + 1] == '/' ||
                  str[count + 1] == '*' || str[count + 1] == '-' ||
                  str[count + 1] == '^')) {
        result = 0;
      }
    }
    count++;
  }
  if (scob != 0) {
    result = 0;
  }
  return result;
}

// int main() {
// char src[100] = "-(o(i(a(10.01)*n(2))/10m2))^q(5)";
// int result = check_for_er(src);
//   if (result) {
//     printf("%d\n", result);
//     printf("Kaif");
//   } else {
//     printf("%d\n", result);
//     printf("Error");
//   }
// }
