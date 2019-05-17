/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:35:40 by croxana           #+#    #+#             */
/*   Updated: 2019/05/16 14:41:08 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_tet *head)
{
	int i;
	int c;
	int k;

	i = 0;
	c = 15;
	while (head != NULL)
	{
		while (i < 4)
		{
			while (c > 11)
			{
				k = head->elem[i] >> c;
				if (k & 1)
					write(1, &(head->symbol), 1);
				else
					write(1, ".", 1);				
				c--;
			}
			i++;
			c = 15;
		}
		head = head->next;
	}
}