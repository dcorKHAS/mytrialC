/*Imagine you are a professional thief who plans to rob houses along a street
of n homes. You know the loot at house i is worth mi, for 1 ≤ i ≤ n, but you
cannot rob neighboring houses because their connected security systems will
automatically contact the police if two adjacent houses are broken into. Give an
efficient algorithm to determine the maximum amount of money you can steal
without alerting the police.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int robber(int *houses, int n)
{
	int *max = (int *)malloc(sizeof(int) * n);
	max[0] = houses[0];
	max[1] = MAX(houses[0], houses[1]);
	for (int i = 2; i < n; i++)
	{
		max[i] = MAX(max[i - 1], max[i - 2] + houses[i]);
	}
	return max[n - 1];
}
//The runtime of the algorithm is O(n) and the space complexity is O(n) because of the array max.

int main()
{
	srand(time(NULL));
	int n = 10;
	int *houses = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		houses[i] = rand() % 100;
		printf("%d ", houses[i]);
	}
	printf("\n");
	printf("The maximum amount of money you can steal is %d\n", robber(houses, n));
	free(houses);
	return 0;
}