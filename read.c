/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:55:33 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 15:00:50 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

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
			(tet->elem)[j] = (tet->elem)[j] | (1 << n);
		}
		n--;
	}
	if (i != 4)
		return (0);
	j += (j == 0 && (tet->elem)[j] == 0) ? 0 : 1;
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
	new->map = 2;
	while (i < 4)
		new->elem[i++] = 0;
	new->next = NULL;
}

static t_tet	*ft_new_node(t_tet *head)
{
	t_tet	*new;
	char	sym;

	sym = 'A';
	new = head;
	if (!head)
		new = (t_tet*)malloc(sizeof(t_tet));
	else
	{
		while (new->next)
		{
			new = new->next;
			sym++;
		}
		new->next = (t_tet*)malloc(sizeof(t_tet));
		new = new->next;
		sym++;
	}
	ft_n_node(sym, new);
	return (new);
}

static void		ft_satan(int gnl, t_tet **head, t_tet **tet)
{
	if (gnl == 1)
	{
		*head = ft_new_node(*head);
		*tet = *head;
	}
	else
	{
		while ((*tet)->next)
			*tet = (*tet)->next;
		(*tet)->next = ft_new_node(*head);
		*tet = (*tet)->next;
	}
}

t_tet			*ft_read(char *file_name, t_tet **head)
{
	int		fd;
	char	*line;
	t_tet	*tet;
	int		gnl;

	fd = open(file_name, O_RDONLY);
	gnl = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (gnl == 1 || gnl % 5 == 0)
			ft_satan(gnl, head, &tet);
		if (gnl++ % 5 == 0)
		{
			if (get_next_line(fd, &line) != 1)
				return (NULL);
			gnl++;
		}
		if (ft_new_elem(line, tet) == 0)
			return (NULL);
	}
	close(fd);
	return (*head);
}
