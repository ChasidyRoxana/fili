/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:38:48 by croxana           #+#    #+#             */
/*   Updated: 2019/06/10 14:00:42 by tpepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ELEM (tet->elem)

typedef struct		s_tet
{
	char			symbol;
	int				f_sym;
	int				width;
	int				height;
	int				x;
	int				y;
	int				elem[4];
	struct s_tet	*next;
}					t_tet;

int					ft_read(int fd, t_tet **head);
void				ft_print_map(t_tet *head, int n);
int					ft_solve(t_tet **head);

int					ft_mysqrt(t_tet *head);
void				ft_free_list(t_tet **head);
int					ft_free_str(char **s);

#endif
