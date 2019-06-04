/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:56:07 by croxana           #+#    #+#             */
/*   Updated: 2019/06/04 12:09:54 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"
#include "./includes/array.h"

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
			ELEM[i] <<= tet->f_sym;
		i = -1;
		while (++i < 4)
		{
			k = 0;
			if (ELEM[i] == 0 && i < tet->height)
				tet->height = i;
			while (++k < 5)
				if (((ELEM[i] & (1 << (15 - k))) != 0) && (k + 1 > tet->width))
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

static int		ft_check_tet(t_tet *tet)
{
	int		i;
	int		a;
	int		b;

	while (tet)
	{
		i = 5;
		a = 0;
		while (--i > 0)
			a = a | (ELEM[i - 1] >> (4 * (i - 1)));
		b = a;
		while (b != 0)
		{
			b = b & (b - 1);
			i++;
		}
		if (i != 4)
			return (0);
		while (b < 18 && g_arr[b] != a)
			b++;
		if (g_arr[b] != a)
			return (0);
		tet = tet->next;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_tet	*head;
	t_tet	*tet;
	int		fd;

	head = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!ft_read(fd, &head))
		{
			close(fd);
			return (ft_error(0));
		}
		ft_move(&head);
		tet = head;
		if (!ft_check_tet(head))
			return (ft_error(0));
		if (!ft_solve(&head))
			return (ft_error(0));
	}
	return (0);
}
