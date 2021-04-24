void	qsort(int *v, int left, int right)
{
	int i, last;
	void swap(int *v, int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void	swap(int *v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#include <stdio.h>
#define LEN		10

int	main(void)
{
	int v[LEN] = {0};
	for (int i = 0; i < LEN; ++i)
		v[i] = LEN - i;

	/* before swap */
	for (int i = 0; i < LEN; ++i)
		printf("%d ", v[i]);
	printf("\n");

	qsort(v, 0, 9);

	/* after swap */
	for (int i = 0; i < LEN; ++i)
		printf("%d ", v[i]);
	printf("\n");
	return (0);
}
