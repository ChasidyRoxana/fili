/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:07:23 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:19:19 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i * i < n)
		i++;
	if (i * i == n)
		return (i);
	return (0);
}
