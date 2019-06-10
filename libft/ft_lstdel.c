/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:54:23 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 11:19:58 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*a;

	a = *alst;
	if (alst && del)
	{
		while (a)
		{
			del(a->content, a->content_size);
			a = a->next;
			free(*alst);
			*alst = a;
		}
		*alst = NULL;
	}
}
