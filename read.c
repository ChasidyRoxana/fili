/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:55:33 by croxana           #+#    #+#             */
/*   Updated: 2019/05/17 13:54:30 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tet	*ft_new_node(t_tet *head)
{
	t_tet	*new;
	char	sym;
	int		i;

	sym = 'A';
	i = 0;
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
	new->symbol = sym;
	new->f_sym = -1;
	new->width = -1;
	while (i < 4)
		new->elem[i++] = 0;
	new->next = NULL;
	return(new);
}

int				ft_read(char *file_name)
{
	int		fd;
	char	*line;
	t_tet	*head;
	t_tet	*tet;
	int		gnl;
	int		new;//

	int		i;
	int		j;
	int		n;

	fd = open(file_name, O_RDONLY);
	head = NULL;
	new = 0;
	gnl = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (gnl == new)
		{
			j = 0;
			if (!head)
			{
				head = ft_new_node(head);
				tet = head;
			}
			else
			{
				while (tet->next)
					tet = tet->next;
				tet->next = ft_new_node(head);
				tet = tet->next;
			}
			new += (new == 0 ? 4 : 5);
			if (gnl != 0)
			{
				if (get_next_line(fd, &line) != 1)
					return (0);
				gnl++;
			}
		}
		i = 0;
		n = 15;
		while (line[i] != '\0')
		{
			if (line[i] != '#' && line[i] != '.')
				return (0);
			if (line[i++] == '#')
			{
				if (tet->f_sym == -1 || i < tet->f_sym)
					tet->f_sym = i;
				(tet->elem)[j] = (tet->elem)[j] | (1 << n);
			}
			n--;
		}
		if (i != 4)
			return (0);
		gnl++;
		j += (j == 0 && (tet->elem)[j] == 0) ? 0 : 1;
	}
	close(fd);
	ft_print_map(head);
	return (1);
}
