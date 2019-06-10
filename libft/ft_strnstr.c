/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:05:25 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:39 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && n < len)
	{
		if (*haystack == *needle)
		{
			while (needle[i] && haystack[i] == needle[i])
				i++;
			if (!(needle[i]) && (n + i) <= len)
				return ((char *)haystack);
			i = 0;
		}
		haystack++;
		n++;
	}
	return (NULL);
}
