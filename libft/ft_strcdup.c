/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:13:03 by croxana           #+#    #+#             */
/*   Updated: 2019/05/30 19:16:08 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcdup(const char *s, int c)
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(s2 = ft_strnew(i)))
		return (NULL);
	while (*s && j < i)
		s2[j++] = *s++;
	s2[i] = '\0';
	return (s2);
}
