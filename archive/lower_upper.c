#include <stdio.h>
int main(void)
{
    char ans[10000] = {'\0'};
    scanf("%s", ans);
    int length = 0;
    int i = 0;
    while (ans[i] != '\0')
    {
        i++;
        length++;
    }

    int cap = 0, lower = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (ans[i] >= 65 && ans[i] <= 90)
        {
            cap = 1;
        }
        if (ans[i] >= 97 && ans[i] <= 122)
        {
            lower = 1;
        }
    }
    printf("%s", (cap && lower) ? "Mix" : (cap ? "All Capital Letter" : "All Small Letter"));
}