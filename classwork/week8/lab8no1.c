#include <stdio.h>
#include <string.h>

int findMax(int num[]);
void addone(int number[], int add[]);
void addtwo(int number[], int pos[], int x);
void addthree(int number[], int pos[][2]);
void main()
{
	int number[5] = {20, 50, 100, 99, 9};
	int add[5] = {5, 5, 5, 5, 5};
	int pos[5] = {1, 3, 5};
	int auto_increment = 5;
	int POS[][2] = {
		{0, 5},
		{2, 5},
		{4, 5}};
	int max;

	max = findMax(number);
	printf("number[1] : %d\n", number[0]);
	printf("number[2] : %d\n", number[1]);
	printf("number[3] : %d\n", number[2]);
	printf("number[4] : %d\n", number[3]);
	printf("number[5] : %d\n", number[4]);
	printf("Maximum of these number is %d\n", max);

	addone(number, add);
	pArray(number);
	max = findMax(number);
	printf("Maximum of these number is %d\n", max);

	addtwo(number, pos, auto_increment);
	pArray(number);
	max = findMax(number);
	printf("Maximum of these number is %d\n", max);

	addthree(number, POS);
	pArray(number);
	max = findMax(number);
	printf("Maximum of these number is %d\n", max);
}

int findMax(int num[])
{
	int maximum, i = 0;
	maximum = num[i];

	for (i = 0; i < 5; i++)
	{
		if (num[i] > maximum)
			maximum = num[i];
	}
	return maximum;
}

void pArray(int number[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("number[%d] : %d\n", i + 1, number[i]);
	}
}

void addone(int number[], int add[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		number[i] += add[i];
	}
}

void addtwo(int number[], int pos[], int x)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		number[pos[i] - 1] += x;
	}
}

void addthree(int number[], int pos[][2])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		number[pos[i][0]] += pos[i][1];
	}
}