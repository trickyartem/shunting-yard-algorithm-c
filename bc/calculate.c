#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "main.h"

char *calculate(output_queue *queue) {
    stack *_stack = malloc(sizeof(stack));
    while (queue->next != NULL) {
        if (queue->token_type == NUMBER) {
            _stack = push_to_stack(_stack, queue->value, queue->token_type);
        } else if (queue->token_type == SIGN) {
            int right_operand = atoi(pop_from_stack(&_stack));
            int left_operand = atoi(pop_from_stack(&_stack));
            int result = check_operator_and_perform_action(left_operand, right_operand, *queue->value);
            char string_result[100];

            sprintf(string_result, "%d", result);
            _stack = push_to_stack(_stack, strdup(string_result), NUMBER);
        }
        queue = queue->next;
    }

    // destroy_stack(&_stack);
    return _stack->token;
}