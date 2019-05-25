/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:02:01 by croxana           #+#    #+#             */
/*   Updated: 2019/05/25 14:35:26 by tpepperm         ###   ########.fr       */
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
/*
int	main(int ac, char **av)
{
	char	**line;
	int		fd;
	//int		fd1;
	int		ret;

	line = (char**)malloc(1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
		//for(int i = 0; i < 5; i++)
		//{
		//	if (get_next_line(fd, line) == 1)
		//		printf("%s\n", *line);
		//	if (get_next_line(fd1, line) == 1)
		//		printf("%s\n", *line);
		//}
		while ((ret = get_next_line(fd, line)) == 1)
			printf("ret: %d -- %s\n", ret, *line);
		printf("ret: %d\n", ret);
		printf("UFF, TRY AGAIN OR... THE END?\n");
		close(fd);
	}
	else
		printf("FILE NAME MISSING");
	free(line);
	return (0);
}*/
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line.h ft_memmove.c ft_strchr.c ft_strcdup.c ft_strlen.c ft_strnew.c ft_strjoin.c ft_strdup.c