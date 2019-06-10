/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:10:04 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:30 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	int		i;
	int		o;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	o = 0;
	while ((s[i] == 32 || s[i] == 10 || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j] == 32 || s[j] == 10 || s[j] == '\t') && j > 0)
		j--;
	if (!(a = ft_strnew(i < j ? (j - i + 1) : 0)))
		return (NULL);
	while (i <= j)
		a[o++] = s[i++];
	return (a);
}
