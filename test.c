#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

int main() {
    int a = 0x7FFFFFFF;
    int i = 0;
    int *arr = NULL;
    int count = 0;

    while (a != 0) {
        count++;
        int test = a % 10;
        arr = realloc(arr, sizeof(int) * count);
        arr[count - 1] = test;
        a /= 10;
    }

    int result = 0;
    for (uint32_t i = count, j = 0; i > 0; i--, j++) {
        int m = pow(10, i - 1) * arr[j];
        result += m;
    }
 
    printf("%d", result);
}