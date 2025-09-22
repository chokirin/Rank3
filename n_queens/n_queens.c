/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:44:26 by xinzhang          #+#    #+#             */
/*   Updated: 2025/08/20 16:49:02 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long mask;

void	disp(int *q, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d", q[i]);
	printf("\n");
}

/* backtracking colonne par colonne, avec trois masques disjoints */
void	bt(int n, int col, int *q, mask rows, mask d1, mask d2)
{
	if (col == n)
	{
		disp(q, n);
		return;
	}
	for (int r = 0; r < n; ++r)
	{
		/* On vérifie la rangée */
		mask rm  = 1UL << r;

		/* On vérifie les deux diagonales */
		mask d1m = 1UL << (col + r);
		mask d2m = 1UL << (r - col + n);

		if (!(rows & rm) && !(d1 & d1m) && !(d2 & d2m))
		{
			q[col] = r;
			bt(n, col + 1, q, rows | rm, d1 | d1m, d2 | d2m);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
		
	int n = atoi(av[1]);
	int q[32]; 

	bt(n, 0, q, 0, 0, 0);
	return (0);
}