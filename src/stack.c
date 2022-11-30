#include "stack.h"

void push(stack **head, double value, int type, int priority) {
  stack *tmp = (stack *)malloc(sizeof(stack));
  tmp->value = value;
  tmp->type = type;
  tmp->prior = priority;
  tmp->next = (*head);
  (*head) = tmp;
}

stack pop(stack **head) {
  stack *prev = NULL;
  stack tmp = {0};
  prev = (*head);
  tmp.value = prev->value;
  tmp.type = prev->type;
  tmp.prior = prev->prior;
  (*head) = (*head)->next;
  free(prev);
  return tmp;
}

stack top(stack **head) {
  stack *tmp = (*head);
  return *tmp;
}

int topSimType(stack **head) { return (*head)->type; }