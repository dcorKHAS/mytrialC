/*Basketball games are a sequence of 2-point shots, 3-point shots, and 1-point
free throws. Give an algorithm that computes how many possible scoring se-
quences add up to a given n. For n = 5 there are thirteen possible sequences,
including 1-2-1-1, 3-2, and 1-1-1-1-1.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//The following is a dynamic programming solution.
int basketball(int n)
{
	int *ways = (int *)malloc(sizeof(int) * (n + 1));
	ways[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		ways[i] = 0;
		if (i >= 1)
		{
			ways[i] += ways[i - 1];
		}
		if (i >= 2)
		{
			ways[i] += ways[i - 2];
		}
		if (i >= 3)
		{
			ways[i] += ways[i - 3];
		}
	}
	int result = ways[n];
	free(ways);
	return result;
}

/*Basketball games are a sequence of 2-point shots, 3-point shots, and 1-
point free throws. Give an algorithm that computes how many possible mixes
(1s,2s,3s) of scoring add up to a given n. For n = 5 there are four possible
solutions: (5, 0, 0), (2, 0, 1), (1, 2, 0), and (0, 1, 1).*/

//This differs from the previous problem in that the order of the shots does not matter.
//The following is a dynamic programming solution.