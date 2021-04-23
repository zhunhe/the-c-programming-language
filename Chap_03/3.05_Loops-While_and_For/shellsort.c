#include <stdio.h>
#include <stdlib.h>

#define PRINT	0
#define LEN		1e6

/*
** Shell Sort
** time complexity: O(nlogn^2) Ω(n) θ(nlogn^2)
** space complexity: O(1)
**
** Measure time with worst case
** ./a.out  0.12s user 0.00s system 27% cpu 0.442 total
*/

void	swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void	shellsort(int *list, int len)
{
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; ++i)
		{
			for (int j = i - gap
				; j >= 0 && list[j] > list[j + gap]
				; j -= gap)
			{
				swap(&list[j], &list[j + gap]);
			}
		}
	}
}

void	print_list(int *list, int len)
{
	for (int idx = 0; idx < len; ++idx)
		printf("%d ", list[idx]);
	printf("\n");
}

int	main(void)
{
	int *list;

	if (!(list = (int *)malloc(sizeof(int) * (LEN + 1))))
		return (1);
	for (int idx = 0; idx < LEN; ++idx)
		list[idx] = LEN - idx;
#if PRINT
	printf("before: ");
	print_list(list, LEN);
#endif
	shellsort(list, LEN);
#if PRINT
	printf("after: ");
	print_list(list, LEN);
#endif
	free(list);
	return (0);
}
