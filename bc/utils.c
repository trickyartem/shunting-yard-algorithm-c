#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

bool is_operator(const char value) {
    char *operators = "+-*/^";

    for (int i = 0; i < strlen(operators); i++) {
        if (operators[i] == value) return true;
    }

    return false;
}

bool is_whitespace(const char value) {
    char *whitespace = " \t\n\r\v\0";

    for (int i = 0; i < strlen(whitespace); i++) {
        if (whitespace[i] == value) return true;
    }

    return false;
}

int get_precedence(const char *value) {
    switch (value[0]) {
        case '-': return 0;
        case '+': return 0;
        case '*': return 5;
        case '/': return 5;
        case '^': return 10;
		case '(': return -1;
		case ')': return -1;
	}

    return 0;
}

int check_operator_and_perform_action(int a, int b, char sign) {
    switch (sign) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
		case '^': return pow(a, b);
	}

    return 0;
}
