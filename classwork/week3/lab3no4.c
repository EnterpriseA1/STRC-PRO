#include <stdio.h>

int main()
{
	int score, ans = 0;
	scanf("%d", &score);

	ans = ((score > 29) ? (((score < 40) ? ((printf("You Can Test Again\n")), (printf("You failed by %d", 40 - score))) : (printf("PASS\n"))))
						: (printf("FALSE\n"), (printf("You failed by %d", 30 - score))));
	return 0;
}

// if (score > 29)
// {
// 	if (score < 40)
// 	{
// 		int temp = 40 - score;
// 		printf("You Can Test Again\n");
// 		printf("You failed by %d", temp);
// 	}
// 	else if (score > 39)
// 	{
// 		printf("PASS\n");
// 	}
// }
// else
// {
// 	int temp = 30 - score;
// 	printf("FALSE\n");
// 	printf("You failed by %d", temp);
// }