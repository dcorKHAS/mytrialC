/*Up to k steps in a single bound! A child is running up a staircase with n
steps and can hop between 1 and k steps at a time. Design an algorithm to
count how many possible ways the child can run up the stairs, as a function of
n and k. What is the running time of your algorithm?*/

#include <stdio.h>
#include <stdlib.h>

int memo[1000] = {0};
int memoCount= 0;
int stairs(int n, int k);

int main(int argc, char *argv[])
{

	int n = 30;
	int k= 5;
	printf("%d\n", stairs(n, k));
	return 0;
}

int stairs(int n, int k)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	int i, sum = 0;
	if (memo[n])
	{
		printf("memo used for %d count:%d\n", n, ++memoCount);

		return memo[n];
	}
	for (i = 1; i <= k; i++)
		sum += stairs(n - i, k);
	return memo[n]=sum;
}

// Path: stairs.c
/*A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Design an algorithm to count how many possible ways the child can run up the stairs, as a function of n. What is the running time of your algorithm?*/
//Since we use memoization, the runtime is O(n) and the space complexity is O(n) as well. The runtime is O(n) because we only need to compute each subproblem once, and the space complexity is O(n) because we use an array of size n to store the results of each subproblem.
