#include <stdlib.h>
#include <stdio.h>
#include "main.h"

token *push_to_tokens(token *tokens, char *value, type token_type) {
    token *tmp = (token *)malloc(sizeof(token));

    tmp->value = value;
    tmp->next = tokens;
    tmp->token_type = token_type;
    return tmp;
}

stack *push_to_stack(stack *head, char *element, type token_type) {
    stack *tmp = (stack *)malloc(sizeof(stack));

    tmp->token = element;
    tmp->next = head;
    tmp->token_type = token_type;
    return tmp;
}

output_queue *push_to_queue(output_queue *queue, char *element, type token_type) {
    output_queue *tmp = (output_queue *)malloc(sizeof(output_queue));

    tmp->value = element;
    tmp->next = queue;
    tmp->token_type = token_type;
    return tmp;
}

char *pop_from_queue(output_queue **queue) {
    output_queue *tmp = (*queue)->next;
    if (tmp == NULL) printf("stack is empty\n");

    char *data = (*queue)->value;
    free(*queue);
    *queue = tmp;

    return data;
}

char *pop_from_stack(stack **s) {
    stack *tmp = (*s)->next;
    if (tmp == NULL) printf("stack is empty\n");

    char *data = (*s)->token;
    free(*s);
    *s = tmp;

    return data;
}

void destroy_stack(stack **s) {
    stack *head = *s;

    while (head != NULL) {
        char *s = pop_from_stack(&head);
        free(s);
    }
}

void print_stack(stack *s) {
    stack *tmp = s;

    while (tmp->next != NULL) {
        printf("stack token [%s] [%i]\n", tmp->token, tmp->token_type);
        tmp = tmp->next;
    }
    printf("end of the stack\n");
}

void print_queue(output_queue *q) {
    output_queue *tmp = q;

    while (tmp->next != NULL) {
        printf("queue token [%s] [%i]\n", tmp->value, tmp->token_type);
        tmp = tmp->next;
    }
    printf("end of the queue\n");
}

void print_tokens(token *tokens) {
    token *tmp = tokens;

    while (tmp->next != NULL) {
        printf("token [%s] [%i]\n", tmp->value, tmp->token_type);
        tmp = tmp->next;
    }
}

output_queue *reversed_output_queue(output_queue *s) {
    output_queue *new_head = malloc(sizeof(output_queue));

    while (s->next != NULL) {
        new_head = push_to_queue(new_head, s->value, s->token_type);
        s = s->next;
    }

    return new_head;
}

token *reversed_tokens(token *s) {
    token *new_head = malloc(sizeof(token));

    while (s->next != NULL) {
        new_head = push_to_tokens(new_head, s->value, s->token_type);
        s = s->next;
    }

    return new_head;
}
