/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:53:49 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:18:42 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (size + 1 < size)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
		new[i++] = '\0';
	return (new);
}
