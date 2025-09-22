#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	permu(int *cnt, int n, int depth, char *buf)
{
	if (n == depth)
	{
		buf[n] = '\0';
		puts(buf);
		return;
	}
	for (int c = 0; c < 256; ++c)
	{
		if (cnt[c])
		{
			buf[depth] = (char)c;
			--cnt[c];
			permu(cnt, n, depth + 1, buf);
			++cnt[c];
		}
	}
}
int main(int ac, char **av)
{
	if (ac == 2 && av[1][0])
	{
		int len = strlen(av[1]);
		int cnt[256] = {0};
		char *buf = malloc(len + 1);
		for (int i = 0; i < len; ++i)
			++cnt[(unsigned char)av[1][i]];
		permu(cnt, len, 0, buf);
		free(buf);
	}
	return 0;
}
