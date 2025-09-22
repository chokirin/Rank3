#include <stdlib.h>
#include <stdio.h>
typedef unsigned long mask;

void	disp(int n, int *q)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d", q[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
}
void	bt(int n, int col, int *q, mask rows, mask d1, mask d2)
{
	if (col == n)
	{
		disp(n, q);
		return;
	}
	for (int r = 0; r < n; ++r)
	{
		mask rm = 1UL << r;
		mask d1m = 1UL << (r + col);
		mask d2m = 1UL << (r - col + n);
		if (!(rows & rm) && !(d1 & d1m) && !(d2 & d2m))
		{
			q[col] = r;
			bt(n, col + 1, q, rows | rm, d1 | d1m, d2 | d2m);
		}
	}
}
int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int n = atoi(av[1]);
	int q[32];
	bt(n, 0, q, 0, 0, 0);
	return 0;
}