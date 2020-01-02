#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "main.h"

int main() {
    char *exp = "((3 + 2) * 2) + (5 + 35)";
    token *tokens = parser(exp);
    output_queue *queue = infix_to_postfix(tokens);
    char *result = calculate(queue);

    printf("Result is: [%s]\n", result);

    return 0;
}