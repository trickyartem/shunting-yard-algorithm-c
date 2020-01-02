#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "main.h"

output_queue *infix_to_postfix(token *tokens) {
    stack *_stack = malloc(sizeof(stack));
    output_queue *queue = malloc(sizeof(output_queue));
    while (tokens->next != NULL) {
        if (tokens->token_type == NUMBER) {
            queue = push_to_queue(queue, tokens->value, NUMBER);
        } else if (is_operator(*tokens->value)) {
            stack *tmp = _stack;

            if (tmp->next != NULL) {
                char *top_of_stack = tmp->token;
                while (get_precedence(tokens->value) <= get_precedence(top_of_stack)) {
                    char *curr = pop_from_stack(&_stack);
                    queue = push_to_queue(queue, curr, SIGN);
                    if (_stack->token == NULL) {
                        break;
                    }
                    tmp = tmp->next;
                    top_of_stack = tmp->token;
                }
            }

            _stack = push_to_stack(_stack, tokens->value, SIGN);
        } else if (strcmp(tokens->value, "(") == 0) {
            _stack = push_to_stack(_stack, tokens->value, SIGN);
        } else if (strcmp(tokens->value, ")") == 0) {
            while (strcmp(_stack->token, "(")) {
                queue = push_to_queue(queue, pop_from_stack(&_stack), SIGN);
            }
            pop_from_stack(&_stack);
        }
        tokens = tokens->next;
    }


    while (_stack->next != NULL) {
        queue = push_to_queue(queue, _stack->token, SIGN);
        _stack = _stack->next;
    }

    destroy_stack(&_stack);
    queue = reversed_output_queue(queue);
    return queue;
}