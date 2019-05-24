/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:05:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/24 13:02:23 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static int	ft_check_place(int *map, t_tet **tet, int n)
{
	int	i;

	i = 0;
	while (i < (*tet)->height)
	{
		if ((map[(*tet)->y + i] & (((*tet)->elem[i] >> (*tet)->x))) != 0)
		{
			//printf("SYM: %c  Y: %d  X: %d  HEIGHT: %d  WIDHT:%d\n", (*tet)->symbol,(*tet)->y,(*tet)->x,(*tet)->height,(*tet)->width);
			if (((*tet)->x + 1 + (*tet)->width) <= n)
				(*tet)->x += 1;
			else
			{
				if ((*tet)->y + 1 + (*tet)->height > n)
					return 0;
				(*tet)->y += 1;
				(*tet)->x = 0;
			}
			ft_check_place(map, tet, n);
		}
		else
			i++;
	}
	return (1);
}

static int	ft_map(t_tet **head, int n)
{
	int		*map;
	int		i;
	t_tet	*tet;

	i = 0;
	if (!(map = (int *)malloc(sizeof(int) * n)))
		return (0);
	while (i < n)
		map[i++] = 0;
	tet = *head;
	while (tet)
	{
		i = -1;
		if (ft_check_place(map, &tet, n) == 1)
			while (++i < tet->height)
				map[tet->y + i] |= (tet->elem)[i] >> tet->x;
		else
			break ;
		tet = tet->next;
	}
	if (!tet)
		return (n);
	else
	{
		free(map);
		tet = *head;
		while (tet)
		{
			tet->x = 0;
			tet->y = 0;
			tet = tet->next;
		}
		printf("map++\n"); //при увеличении карты Х и У должны обнуляться в каждой фигуре
		return (ft_map(head, n + 1));//чтобы эта лупа корректно подставлялась дальше
	}//но увеличение должно происходить только после того как алгоритм перебрал все 
}//возможные варианты подстановки, когда уже точно не может подставить фигуры в эту map :с

int		ft_solve(t_tet **head)
{
	int		n;

	n = ft_mysqrt(*head);
	if ((n = ft_map(head, n)) != 0){
		ft_print_map(*head, n);
		return (1);}
	else
		return (0);
}