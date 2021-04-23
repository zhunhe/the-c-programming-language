#include <stdio.h>
#include <limits.h>

#define N		1000000
#define FIND		333
#define REPETATION		100000000

/*
** Exercise 3-1.
** Our binary search makes two tests inside the loop,
** when one would suffice (at the price of more tests outside).
** Write a version with only one test inside the loop and measure the difference in run-time.
*/

/*
** <RESULT>
** gcc binsearch.c -o binsearch
** time ./binsearch
**
** ft_binsearch() 0.817s
** ./binsearch  0.43s user 0.00s system 52% cpu 0.817 total
** binsearch() 19.492s
** ./binsearch  19.13s user 0.01s system 98% cpu 19.492 total
*/

int	ft_binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while ((low < high)
		&& (x != v[mid]))
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (x == v[mid] ? mid : -1);
}

int	binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int	main(void)
{
	int idx;
	int v[N];

	for (int idx = 0; idx < N; idx++)
		v[idx] = idx + 1;
	for (int idx = 0; idx < REPETATION; idx++)
	{
#if 0
		ft_binsearch(FIND, v, N);
#else
		binsearch(FIND, v, N);
#endif
	}
	return (0);
}
