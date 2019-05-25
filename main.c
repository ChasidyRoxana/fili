/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:56:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 15:00:23 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

static void		ft_move(t_tet **head)
{
	t_tet	*tmp;
	int		i;
	int		k;

	tmp = *head;
	while (tmp)
	{
		i = -1;
		while (++i < 4)
			(tmp->elem)[i] <<= tmp->f_sym;
		i = -1;
		while (++i < 4)
		{
			k = 0;
			if ((tmp->elem)[i] == 0 && i < tmp->height)
				tmp->height = i;
			while (++k < 5)
				if ((((tmp->elem)[i] & (1 << (15 - k))) != 0) && (k + 1 > tmp->width))
					tmp->width = k + 1;
		}
		tmp->f_sym = 0;
		tmp = tmp->next;
	}
}

int			ft_error(int n)
{
	if (n == 0)
		write(1, "error\n", 7);
	else if (n == 1)
		write(1, "FILE NAME MISSING", 18);
	return (0);
}

int				main(int ac, char **av)
{
	t_tet	*head;

	head = NULL;
	if (ac == 2)
	{
		if (ft_read(av[1], &head) == NULL)
			return (ft_error(0));
		ft_move(&head);
		if (!(ft_solve(&head)))
			return (ft_error(0));
	}
	else
		ft_error(1);;
	return (0);
}