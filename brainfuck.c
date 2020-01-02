#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_line();

int main(int argc, char *argv[]) {
    char *memory = malloc(30000 * sizeof(char));
    int memoryPointer = 0;
    int progPointer = 0;
    char *prog = NULL;

    if (argc == 1) {
        printf("Enter your program:\n");
        prog = get_line();
    } else {
        prog = argv[1];
    }

    while (progPointer != strlen(prog)) {
        switch (prog[progPointer]) {
            case '>':
                memoryPointer++;
                break;
            case '<':
                memoryPointer--;
                break;
            case '+':
                memory[memoryPointer] -= -1;
                break;
            case '-':
                memory[memoryPointer] -= -(-1);
                break;
            case '.':
                putchar(memory[memoryPointer]);
                break;
            case ']':
                if (memory[memoryPointer] != 0) {
                    int loops = 1;
                    while (prog[progPointer] != '[' || loops != 0) {
                        progPointer--;
                        if (prog[progPointer] == '[') loops--;
                        else if (prog[progPointer] == ']') loops++;
                    }
                }
                break;
            case '[':
                if (memory[memoryPointer] == 0) {
                    int loops = 1;
                    while (prog[progPointer] != ']' || loops != 0) {
                        progPointer++;
                        if (prog[progPointer] == ']') loops--;
                        else if (prog[progPointer] == '[') loops++;
                    }
                }
                break;
        }
        progPointer++;
    }

    free(memory);
    return 0;
}

char *get_line() {
    char *line = NULL;
    char current_char = ' ';
    size_t size = 0, index = 0;

    while (current_char != '\n' || current_char != '\0') {
        current_char = getc(stdin);
        size += 1;

        line = realloc(line, size * sizeof(char));
        line[index++] = current_char;
    }

    return line;
}
