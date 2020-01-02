#include <stdlib.h>
#include <stdbool.h>

typedef enum type {
    NUMBER, SIGN
} type;

typedef struct output_queue {
    char *value;
    type token_type;
    struct output_queue *next;
} output_queue;

typedef struct stack {
    char *token;
    type token_type;
    struct stack *next;
} stack;

typedef struct token {
    char *value;
    type token_type;
    struct token *next;
} token;

char *ft_itoa(int n);
int check_operator_and_perform_action(int a, int b, char sign);
int get_precedence(const char *value);
bool is_operator(const char value);
void print_tokens(token *tokens);
bool is_whitespace(const char value);
token *push_to_tokens(token *tokens, char *value, type token_type);
stack *push_to_stack(stack *s, char *element, type token_type);
output_queue *push_to_queue(output_queue *queue, char *element, type token_type);
char *pop_from_stack(stack **s);
char *pop_from_queue(output_queue **queue);
void print_stack(stack *s);
void print_queue(output_queue *queue);
void destroy_stack(stack **s);
token *parser(char *exp);
output_queue *infix_to_postfix(token *token);
output_queue *reversed_output_queue(output_queue *s);
token *reversed_tokens(token *tokens);
char *calculate(output_queue *queue);
