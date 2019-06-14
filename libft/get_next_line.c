/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxana <croxana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:02:01 by croxana           #+#    #+#             */
/*   Updated: 2019/06/14 14:57:11 by croxana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_end(char **line, char *buf)
{
	char	*tp;

	tp = ft_strchr(buf, '\n');
	if (tp)
	{
		*line = ft_strcdup(buf, '\n');
		ft_memmove(buf, &tp[1], ft_strlen(&tp[1]) + 1);
		return (1);
	}
	else if (ft_strlen(buf) > 0)
	{
		*line = ft_strcdup(buf, '\n');
		*buf = 0;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[FD_SIZE];
	int			k;
	char		a[BUFF_SIZE + 1];
	char		*join;

	if (fd < 0 || fd > FD_SIZE)
		return (-1);
	if (!buf[fd] && !(buf[fd] = ft_strnew(0)))
		return (-1);
	while (!ft_strchr(buf[fd], '\n'))
	{
		if ((k = read(fd, a, BUFF_SIZE)) == -1)
			return (-1);
		if (k == 0)
			break ;
		a[k] = '\0';
		join = ft_strjoin(buf[fd], a);
		free(buf[fd]);
		buf[fd] = join;
	}
	return (ft_end(line, buf[fd]));
}
