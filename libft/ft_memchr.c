/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:10:17 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:19:45 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	d;

	str = (char*)s;
	i = 0;
	d = c;
	if (n == 0)
		return (NULL);
	while (*str != d && i++ < n - 1 && str)
		str++;
	if (*str == d && i < n)
		return (str);
	return (NULL);
}
