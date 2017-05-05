/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 03:33:12 by JimmyChe          #+#    #+#             */
/*   Updated: 2016/05/03 18:28:21 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_free_read(char **stock, char **line)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}

static int		ft_check_line(char **stock, char **line)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	tmp = *stock;
	while (tmp[++i] != '\0')
	{
		if ((tmp[i] >= 33 && tmp[i] <= 43) || tmp[i] == 46 || tmp[i] == 47 ||
		(tmp[i] >= 58 && tmp[i] <= 69) || (tmp[i] >= 71 && tmp[i] <= 119) ||
		(tmp[i] >= 121 && tmp[i] <= 126))
			exit(1);
	}
	str = ft_strchr(*stock, '\n');
	if (!str)
		return (0);
	*str = '\0';
	*line = ft_strdup(*stock);
	*stock = ft_strdup(str + 1);
	free(tmp);
	return (1);
}

static char		*ft_strjoin_free(char *start, char *buf, int s)
{
	int		size1;
	int		size2;
	char	*sol;

	size1 = start != NULL ? ft_strlen(start) : 0;
	size2 = buf != NULL ? ft_strlen(buf) : 0;
	sol = (char *)ft_memalloc(sizeof(char) * (size1 + size2 + 1));
	size1 = -1;
	while (start && start[++size1])
		sol[size1] = start[size1];
	if (start && (s == 1 || s == 3))
		free(start);
	size2 = -1;
	while (buf && buf[++size2])
		sol[size1 + size2] = buf[size2];
	if (buf && (s == 2 || s == 3))
		free(buf);
	return (sol);
}

int				get_next_line(int const fd, char **line)
{
	static char		*start[200];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > 200 ||
		line == NULL || BUFF_SIZE <= 0 || BUFF_SIZE > MAX_BUF)
		return (-1);
	if (start[fd] && ft_check_line(&(start[fd]), line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		start[fd] = (start[fd] ?
			ft_strjoin_free(start[fd], buf, 1) : ft_strdup(buf));
		if (ft_check_line(&(start[fd]), line))
			return (1);
	}
	if (start[fd] && ret >= 0)
		return (ft_free_read(&(start[fd]), line));
	return (ret > 0 ? 1 : ret);
}
