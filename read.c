/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:55:33 by croxana           #+#    #+#             */
/*   Updated: 2019/06/10 15:09:59 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include "./includes/libft.h"

static int		ft_new_elem(char *line, t_tet *tet)
{
	int			i;
	static int	j;
	int			n;

	i = 0;
	n = 15;
	if (tet->f_sym == -1)
		j = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '#' && line[i] != '.')
			return (0);
		if (line[i++] == '#')
		{
			if (tet->f_sym == -1 || i - 1 < tet->f_sym)
				tet->f_sym = i - 1;
			ELEM[j] = ELEM[j] | (1 << n);
		}
		n--;
	}
	if (i != 4)
		return (0);
	j += (j == 0 && ELEM[j] == 0) ? 0 : 1;
	return (1);
}

static void		ft_n_node(char sym, t_tet *new)
{
	int	i;

	i = 0;
	new->symbol = sym;
	new->f_sym = -1;
	new->width = 1;
	new->height = 4;
	new->x = 0;
	new->y = 0;
	while (i < 4)
		*(new->elem + i++) = 0;
	new->next = NULL;
}

static int		ft_satan(int gnl, t_tet **head, t_tet **tet)
{
	char	sym;

	sym = 'A';
	*tet = *head;
	if (gnl == 1)
	{
		if (!(*head = (t_tet*)malloc(sizeof(t_tet))))
			return (0);
		*tet = *head;
	}
	else
	{
		while ((*tet)->next)
		{
			*tet = (*tet)->next;
			sym++;
		}
		if (!((*tet)->next = (t_tet*)malloc(sizeof(t_tet))))
			return (0);
		*tet = (*tet)->next;
		sym++;
	}
	ft_n_node(sym, *tet);
	return (1);
}

int				ft_read(int fd, t_tet **head)
{
	char	*line;
	t_tet	*tet;
	int		gnl;

	gnl = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (gnl == 1 || gnl % 5 == 0)
			if (!ft_satan(gnl, head, &tet))
				return (0);
		if (gnl++ % 5 == 0)
		{
			if (*line != '\0')
			{
				free(line);
				return (0);
			}
			free(line);
			get_next_line(fd, &line);
			gnl++;
		}
		if (ft_new_elem(line, tet) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (gnl == 1 || gnl % 5 != 0)
		return (0);
	close(fd);
	return (1);
}
