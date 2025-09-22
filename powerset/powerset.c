/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:45:41 by xinzhang          #+#    #+#             */
/*   Updated: 2025/08/20 18:59:51 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	int k = ac - 2, target = atoi(av[1]), found = 0;
	for (unsigned long m = 1; m < (1UL << k); ++m)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
			if (m & (1UL << i)) 
				sum += atoi(av[i + 2]);
		if (sum == target)
		{
			found = 1;
			for (int i = 0; i < k; i++)
				if (m & (1UL << i))
					printf("%s%s", (i && m & ((1UL << i) - 1)) ? " " : "", av[i + 2]);
			printf("\n");
		}
	}
	if (!found)
		printf("\n");
	return 0;
}
