/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:05:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/27 16:36:13 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"

static int	ft_mysqrt(t_tet *head)
{
	int		i;
	int		j;
	t_tet 	*tet;

	i = 1;
	j = 1;
	tet = head;
	while (tet->next)
	{
		tet = tet->next;
		i++;
	}
	i *= 4;
	while (j * j < i)
		j++;
	if (j * j != i)
		return (j - 1);
	return (j);
}

int		ft_move_yx(t_tet **tet, int n)
{
	if (((*tet)->x + 1 + (*tet)->width) <= n)
		(*tet)->x += 1;
	else
	{
		//if ((*tet)->y + 1 + (*tet)->height > n)
		//	return (0);
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

static int	ft_map(int *map, t_tet **head, int n)
{
	int		i;
	t_tet	*tet;

	tet = *head;
	if (!tet)
		return (1);
	while (tet && (tet->y + tet->height) <= n)
	{
		if (ft_check_place(map, &tet, n))
		{
			i = -1;
			while (++i < tet->height)
				map[tet->y + i] |= (tet->elem)[i] >> tet->x;
			if (ft_map(map, &tet->next, n))
				return 1;
			i = -1;
			while (++i < tet->height)
				map[tet->y + i] ^= (tet->elem)[i] >> tet->x;
		}
		ft_move_yx(&tet, n);
	}
	if (tet && tet->y + tet->height > n)
	{
		tet->y = 0;
		tet->x = 0;
	}
	return 0;
}

int		ft_solve(t_tet **head)
{
	int		n;
	int		*map;
	t_tet	*tet;
	int		i;

	i = 0;
	n = ft_mysqrt(*head);
	if (!(map = (int *)malloc(sizeof(int) * n)))
		return (0);
	while (i < n)
		map[i++] = 0;
	printf("N: %d\n", n);
	while (!ft_map(map, head, n))
	{
		ft_print_map(*head, n);
		free (map);
		tet = *head;
		while (tet)
		{
			tet->x = 0;
			tet->y = 0;
			tet = tet->next;
		}
		if (!(map = (int *)malloc(sizeof(int) * ++n)))
			return (0);
		printf("N: %d\n", n);
		i = 0;
		while (i < n)
			map[i++] = 0;
	}
	ft_print_map(*head, n);
	return (1);
}