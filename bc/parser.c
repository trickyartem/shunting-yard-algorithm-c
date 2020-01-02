#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

token *parser(char *exp) {
    token *tokens = malloc(sizeof(token));
    int token_type = 0;
    char *token_value = malloc(sizeof(char));
    int i = 0;

    for (size_t i = 0; i < strlen(exp); i++) {
        if (is_whitespace(exp[i])) {
            continue;
        } else if (is_operator(exp[i]) || exp[i] == '(' || exp[i] == ')'){
            token_value = realloc(token_value, sizeof(char) * 2);
            token_value[0] = exp[i];
            token_value[1] = '\0';
            token_type = SIGN;
        } else {
            int n_length = 0;
            while ((!is_whitespace(exp[i]) && !is_operator(exp[i])) && exp[i] != '(' && exp[i] != ')' ) {
                token_value = realloc(token_value, sizeof(char) * n_length + 1);
                token_value[n_length++] = exp[i++];
            }
            i--;
            token_value[n_length] = '\0';
            token_type = NUMBER;
        }
        tokens = push_to_tokens(tokens, token_value, token_type);
        token_value = NULL;
    }

    tokens = reversed_tokens(tokens);
    return tokens;
}
