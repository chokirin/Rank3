#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* récursion avec table de fréquences */
void	perm(int *cnt, int n, int depth, char *buf)
{
	int	c;

	if (depth == n)
	{
		buf[n] = '\0';
		puts(buf);
		return;
	}
	for (c = 0; c < 256; ++c)
		if (cnt[c])
		{
			buf[depth] = (char)c;
			--cnt[c];
			perm(cnt, n, depth + 1, buf);
			++cnt[c];
		}
}

int	main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int	 n = strlen(av[1]);
		int	 cnt[256] = {0};
		char	*buf = malloc(n + 1);

		for (int i = 0; i < n; ++i)
			++cnt[(unsigned char)av[1][i]];
		perm(cnt, n, 0, buf);
		free(buf);
	}
	return 0;
}