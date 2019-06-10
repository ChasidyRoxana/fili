/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:00:28 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:53 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*a;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(a = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
		a[i++] = f(*s++);
	return (a);
}
