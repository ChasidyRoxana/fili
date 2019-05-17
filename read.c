/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:55:33 by croxana           #+#    #+#             */
/*   Updated: 2019/05/16 14:55:20 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_new_node(t_tet *head)
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
		while (new->next != NULL)
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

int	ft_read(char *file_name)
{
	int		fd;
	char	**line;
	int		i;
	int		j;
	t_tet	*head;
	int		n;
	t_tet	*tet;
	int		new;
	int 	gnl;

	fd = open(file_name, O_RDONLY);
	line = malloc(1);
	head = NULL;
	new = 0;
	gnl = 0;
	while (get_next_line(fd, line) == 1)
	{
		printf("while\n");
		if (gnl == new)
		{
			j = 0;
			printf("tet\n");
			tet = ft_new_node(head);
			new += (new == 0 ? 4 : 5);
			if (gnl != 0)
			{
				if (get_next_line(fd, line) != 1){printf("1 if in while\n");
					return (0);}
				gnl++;
			}
		}
		i = 0;
		n = 15;
		while(*line[i] != '\0')
		{
			printf("line[i]\n");
			if (*line[i] != '#' && *line[i] != '.'){printf("1 if while while\n");
				return (0);}
			if (*line[i] == '#')
			{
				printf("if == #\n");
				if (tet->f_sym == -1 || i < tet->f_sym)
					tet->f_sym = i;
				(tet->elem)[j] = (tet->elem)[j] | (1 << n);
			}
			i++;
			n--;
		}
		if (i != 4){printf("i: %d\n", i);
			return (0);}
		gnl++;
		j += (j == 0 && (tet->elem)[j] == 0) ? 0 : 1;
	}
	close(fd);
	ft_print_map(head);
	return (1);
}