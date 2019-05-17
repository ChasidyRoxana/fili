/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:02:07 by croxana           #+#    #+#             */
/*   Updated: 2019/05/16 14:27:35 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 32
# define FD_SIZE 10240

int					get_next_line(const int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strcdup(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);

#endif
