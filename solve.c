/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:05:07 by croxana           #+#    #+#             */
/*   Updated: 2019/06/10 15:10:03 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"

int			ft_move_yx(t_tet **tet, int n)
{
	if (((*tet)->x + 1 + (*tet)->width) <= n)
		(*tet)->x += 1;
	else
	{
		(*tet)->y += 1;
		(*tet)->x = 0;
	}
	return (1);
}

static int	ft_check_place(int *map, t_tet **tet, int n)
{
	int	i;

	i = 0;
	while (i < (*tet)->height)
	{
		if ((map[(*tet)->y + i] & (((*tet)->elem[i] >> (*tet)->x))) != 0)
		{
			ft_move_yx(tet, n);
			if ((*tet)->y + (*tet)->height > n)
				return (0);
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

static void	ft_bitinmap(int *map, t_tet *tet)
{
	int i;

	i = -1;
	while (++i < tet->height)
		map[tet->y + i] ^= ELEM[i] >> tet->x;
}

static int	ft_map(int *map, t_tet **head, int n)
{
	t_tet	*tet;

	tet = *head;
	if (!tet)
		return (1);
	while ((tet->y + tet->height) <= n && (tet->x + tet->width) <= n)
	{
		if (ft_check_place(map, &tet, n))
		{
			ft_bitinmap(map, tet);
			if (ft_map(map, &tet->next, n))
				return (1);
			ft_bitinmap(map, tet);
		}
		ft_move_yx(&tet, n);
	}
	tet->y = 0;
	tet->x = 0;
	return (0);
}

int			ft_solve(t_tet **head)
{
	int		n;
	int		*map;
	int		i;

	i = 0;
	n = ft_mysqrt(*head);
	if (!(map = (int *)malloc(sizeof(int) * n)))
		return (0);
	while (i < n)
		map[i++] = 0;
	while (!ft_map(map, head, n))
	{
		free(map);
		if (!(map = (int *)malloc(sizeof(int) * ++n)))
			return (0);
		i = 0;
		while (i < n)
			map[i++] = 0;
	}
	free(map);
	ft_print_map(*head, n);
	return (1);
}
