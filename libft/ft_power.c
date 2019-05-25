/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:20:30 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:19:35 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_power(int n, int pow)
{
	int		p;
	long	res;

	p = 0;
	res = 1;
	while (p++ < pow)
		res = res * n;
	return (res);
}
