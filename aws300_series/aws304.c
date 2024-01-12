#include <stdio.h>
int main(void)
{

    int k = 20;
    char sol[k];
    scanf("%s", &sol);

    int n, i, j, count = 0;
    char ans[k];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", &ans);
        count = 0;
        for (j = 0; j < k; j++)
        {
            if (ans[j] == sol[j])
            {
                if (j < 15)
                {
                    count++;
                }
                else if (j < 18)
                {
                    count += 2;
                }
                else
                {
                    count += 3;
                }
            }
        }
        printf("std %d => %d\n", i + 1, count);
    }

    return 0;
}