/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:35:40 by croxana           #+#    #+#             */
/*   Updated: 2019/05/17 13:35:25 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_tet *head)
{
	int i;
	int c;
	int k;

	//printf("print\n");
	while (head != NULL)
	{
		i = -1;
		while (++i < 4)
		{
			c = 15;
			while (c > 11)
			{
				k = (head->elem)[i] >> c--;
				if (k & 1)
					write(1, &(head->symbol), 1);
				else
					write(1, ".", 1);
			}
			write(1, "\n", 1);
		}
		head = head->next;
		write(1, "\n", 1);
	}
}