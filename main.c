/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:56:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/29 13:53:01 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"

int				ft_mysqrt(t_tet *head)
{
	int		i;
	int		j;
	t_tet	*tet;

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

static void		ft_move(t_tet **head)
{
	t_tet	*tet;
	int		i;
	int		k;

	tet = *head;
	while (tet)
	{
		i = -1;
		while (++i < 4)
			ELEM_I <<= tet->f_sym;
		i = -1;
		while (++i < 4)
		{
			k = 0;
			if (ELEM_I == 0 && i < tet->height)
				tet->height = i;
			while (++k < 5)
				if (((ELEM_I & (1 << (7 - k))) != 0) && (k + 1 > tet->width))
					tet->width = k + 1;
		}
		tet->f_sym = 0;
		tet = tet->next;
	}
}

int				ft_error(int n)
{
	ft_putendl_fd("error", 1);
	return (0);
}

int				main(int ac, char **av)
{
	t_tet	*head;

	head = NULL;
	if (ac == 2)
	{
		if (!ft_read(av[1], &head))
			return (ft_error(0));
		ft_move(&head);
		if (!ft_solve(&head))
			return (ft_error(0));
	}
	return (0);
}
