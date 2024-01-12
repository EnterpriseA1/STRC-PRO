#include <stdio.h>
#include <stdlib.h>

int is_prime(int x) {
    if (x < 2) {
        return 0;  
    }
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int *numbers = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        if (is_prime(numbers[i])) {
            printf("y");
        } else {
            printf("n");
        }
        printf("\n");
    }
    free(numbers);
    return 0;
}