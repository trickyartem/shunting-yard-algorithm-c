#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct stack {
    int data;
    struct stack *NEXT;
} stack;

stack *push(stack *head, int data) {
    stack *tmp = (stack *)malloc(sizeof(stack));

    tmp->data = data;
    tmp->NEXT = head;
    return tmp;
}

int pop(stack *head) {
    stack *tmp = head->NEXT;
    if (tmp == NULL) printf("stack is empty\n");

    int data = head->data;
    *head = *tmp;

    return data;
}

int main() {
    stack *head = NULL;

    for (int i = 0; i < 102; i++) {
        head = push(head, i);
    }

    for (int i = 0; i < 100; i++) {
        pop(head);
    }
    printf("%d\n", head->data);
}

