/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:23:16 by xinzhang          #+#    #+#             */
/*   Updated: 2025/08/21 13:42:11 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char *found, *p, *buf;
	char c;
	int	i = 0, size = 1024, len, ret;
	if (ac != 2 || !av[1][0])
		return 1;
	len = strlen(av[1]);
	buf = malloc(size);
	if (!buf)
	{
		fprintf(stderr, "Error: malloc failed!\n");
		return 1;
	}
	while ((ret = read(0, &c, 1)) > 0)
	{
		if (i > size - 1)
		{
			size *= 2;
			buf = realloc(buf, size);
			if (!buf)
			{
				fprintf(stderr, "Error: realloc failed!\n");
				return 1;
			}
		}
		buf[i++] = c;
	}
	if (ret < 0)
	{
		perror("Error");
		return 1;
	}
	buf[i] = '\0';
	p = buf;
	while ((found = (memmem(p, strlen(p), av[1], len))))
	{
		*found = 0;
		printf("%s", p);
		for (int j = 0; j < len; ++j)
			printf("*");
		p = found + len;
	}
	printf("%s", p);
	free(buf);
	return 0;
}