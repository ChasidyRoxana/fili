/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:35:40 by croxana           #+#    #+#             */
/*   Updated: 2019/05/24 12:34:10 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_tet *head, int n)
{
	char	map[n][n];
	int		i;
	int		k;
	int		c;
	int		j;
	t_tet	*tet;

	tet = head;
	j = -1;
	while (++j < n)
		ft_memset(&map[j], '.', n);
	printf("print > while tet, N: %d>>\n", n);
	while (tet)
	{
		i = -1;
		j = 0;
		while (++i < tet->height)
		{
			c = 15;
			k = 0;
			while (c > 15 - tet->width)
			{
				if (((tet->elem)[i] >> c--) & 1)
					map[tet->y + j][tet->x + k] = tet->symbol;
				k++;
			}
			j++;
		}
		tet = tet->next;
	}
	j = -1;
	while (++j < n)
	{
		write(1, &map[j], n);
		write(1, "\n", 1);
	}
}