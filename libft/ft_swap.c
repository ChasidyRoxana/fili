/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:45:01 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:28 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = 0;
	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
}