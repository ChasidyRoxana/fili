/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:38:48 by croxana           #+#    #+#             */
/*   Updated: 2019/05/16 14:42:54 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // удалить это не забудь

# define BUFF_SIZE 32
# define FD_SIZE 10240
# include <string.h>

typedef struct		s_tet
{
	char			symbol;
	int				f_sym;
	int				width;
	int				elem[4];
	struct s_tet	*next;
}					t_tet;

int		ft_read(char *file_name);
void	ft_print_map(t_tet *head);


int					get_next_line(const int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strcdup(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);


#endif