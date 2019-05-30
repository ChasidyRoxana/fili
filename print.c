/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:35:40 by croxana           #+#    #+#             */
/*   Updated: 2019/05/30 18:14:21 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"

static void	ft_putbit(char map[], t_tet *tet, int j)
{
	int	c;
	int	k;

	c = 15;
	k = 0;
	while (c > 15 - tet->width)
	{
		if ((tet->elem[j] >> c--) & 1)
			map[tet->x + k] = tet->symbol;
		k++;
	}
	j++;
}

void		ft_print_map(t_tet *head, int n)
{
	char	map[n][n];
	int		j;
	t_tet	*tet;

	tet = head;
	j = -1;
	while (++j < n)
		ft_memset(&map[j], '.', n);
	while (tet)
	{
		j = -1;
		while (++j < tet->height)
			ft_putbit(map[j + tet->y], tet, j);
		tet = tet->next;
	}
	j = -1;
	while (++j < n)
	{
		write(1, &map[j], n);
		write(1, "\n", 1);
	}
}
