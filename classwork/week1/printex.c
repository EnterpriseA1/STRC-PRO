#include <stdio.h>

int main(void)
{
	int no_of_day;
	float commission = 5000.00;
	float percent;
	percent = 0.05;
	no_of_day = 7;
	printf("%5s %6.2f%-3%", "rate:", percent);
	printf("\n%-6s%s%-8.2f", "comm", ":", commission);
	printf("\n%9s%d%s", "no.of day:", no_of_day, "days");
}
