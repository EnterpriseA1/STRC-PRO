#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int k = 0, n = 0;
    char *sol = NULL;
    scanf("%d", &k);
    sol = malloc(sizeof(char) * k + 1);
    scanf("%s", sol);

    int i, j;
    scanf("%d", &n);

    char *ans = NULL;
    ans = malloc(sizeof(char) * k + 1);

    int count = 0;
    for (i = 0; i < n; i++, count = 0)
    {
        scanf("%s", ans);
        for (j = 0; j < k; j++)
        {
            if (ans[j] == sol[j])
            {
                count++;
            }
        }
        printf("std %d => %d\n", i + 1, count);
    }

    free(sol);
    free(ans);
    return 0;
}

// pro method//
//  int k = 0;
//  scanf("%d", &k);
//  char sol[k];

// scanf("%s", &sol);
// int n, i = 0, j = 0, count = 0;
// char ans[k];

// scanf("%d", &n);
// while ((i < n) ? count = 0, j = 0, scanf("%s", &ans), ++i : 0)
// {
//     while ((j < k ? (ans[j] == sol[j] ? count++ : 0), ++j : 0))
//     {
//     }
//     printf("std %d => %d\n", i, count);
// }