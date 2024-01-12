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
    int i, result = 0;
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
}

void fourTosix(char bit[])
{
    bit[4] = '1';
    bit[2] = '1';
}

void inverseSecond(char bit[])
{
    if (bit[6] == '1')
    {
        bit[6] = '0';
    }
    else
    {
        bit[6] = '1';
    }
}

void resetval(char reset[], char bit[])
{
    int i;
    for (i = 0; i < 8; i++)
    {
        reset[i] = bit[i];
    }
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

    char mod_bit[9];
    binary(num, bit);

    for (i = 0; i < 8; i++)
    {
        mod_bit[i] = bit[i];
    }
    mod_bit[8] = '\0';

    oneTothree(mod_bit);
    printf("%d 0b%s\n", decimal(mod_bit), mod_bit);

    resetval(mod_bit, bit);
    fourTosix(mod_bit);
    printf("%d 0b%s\n", decimal(mod_bit), mod_bit);

    resetval(mod_bit, bit);
    inverseSecond(mod_bit);
    printf("%d 0b%s\n", decimal(mod_bit), mod_bit);

    binary(num, bit);
    printf("%d 0b%s\n", decimal(bit), bit);
    return 0;
}