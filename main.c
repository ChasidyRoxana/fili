/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:56:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/16 14:45:45 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int n)
{
	if (n == 0)
		write(1, "error\n", 7);
    else if (n == 1)
        write(1, "FILE NAME MISSING", 18);
}

int		main(int ac, char **av)
{
    int t;
    if (ac == 2)
    {
        t = ft_read(av[1]);
        if (t == 0)
            ft_error(0);
    }
    else
        ft_error(1);;
    return (0);
}