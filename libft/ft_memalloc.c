/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:51:08 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:19:49 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*kek;
	size_t	i;

	i = 0;
	if (!(kek = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	return ((void *)kek);
}
