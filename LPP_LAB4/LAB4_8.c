#include <stdio.h>
#include <stdlib.h>

void shrink_bitArray(char **destArray, int *length, int num);

int main() {
    int n;
    scanf("%d", &n);
    int length = 0;
    char *x = NULL;
    int i;
    int count = 0;
    shrink_bitArray(&x, &length, n);
    for (i = 0; i < length; i++) {
        if (x[i] == '1'){
            count++;
        }
    }
    printf("%d",count);
    free(x); 
    return 0;
}

void shrink_bitArray(char **destArray, int *length, int num) {
    int divider = 2;
    if (num == 0) {
        *destArray = realloc(*destArray, (*length + 1) * sizeof(char));
        (*destArray)[*length] = '0';
        (*length)++;
    }
    while (num > 0) {
        int temp = num;
        int result = temp % divider;
        num /= divider;
        char *temp_char = realloc(*destArray, (*length + 1) * sizeof(char));
        *destArray = temp_char;
        (*destArray)[*length] = result + '0';
        (*length)++;
    }
}
