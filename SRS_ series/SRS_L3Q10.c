#include <stdio.h>
#include <stdlib.h>

void binary(int num, char bit[])
{
    int i = 7;
    while (num > 0)
    {
        int temp = num;
        num = num / 2;
        bit[i] = (temp % 2) + '0';
        i--;
    }
}

int decimal(char bit[])
{
    int i, result;
    for (i = 7; i >= 0; i--)
    {
        if (bit[i] == '1')
        {
            result += (1 << (7 - i));
        }
    }
    return result;
}

void oneTothree(char bit[])
{
    bit[7] = '0';
    bit[5] = '0';
    printf("0b%s", bit);
}

int main(void)
{
    int num, i;
    char bit[9];
    int bitSize = sizeof(bit);
    scanf("%d", &num);

    for (i = 0; i < bitSize - 1; i++)
    {
        bit[i] = '0';
    }
    bit[8] = '\0';
    binary(num, bit);
    printf("\n%d ", decimal(bit));
    oneTothree(bit);

    return 0;
}