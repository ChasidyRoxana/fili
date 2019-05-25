/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:01:52 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:51 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*a;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(a = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
