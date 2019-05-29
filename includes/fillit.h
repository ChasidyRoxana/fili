/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:38:48 by croxana           #+#    #+#             */
/*   Updated: 2019/05/29 13:28:38 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h> // удалить это не забудь
# include <stdint.h>

# define ELEM_I (tet->elem)[i]

typedef struct		s_tet
{
	char			symbol;
	int				f_sym;
	int				width;
	int				height;
	int				x;
	int				y;
	uint8_t			elem[4];
	struct s_tet	*next;
}					t_tet;

t_tet				*ft_read(char *file_name, t_tet **head);
void				ft_print_map(t_tet *head, int n);
int					ft_solve(t_tet **head);

int					ft_mysqrt(t_tet *head);

#endif