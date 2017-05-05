/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:32 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/03 17:55:12 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_params(int ac, char **av, int *fd)
{
	if (ac == 1 || ac > 2)
	{
		if (ac == 1)
			ft_putstr("Too few arguments\n");
		else
			ft_putstr("Too many arguments\n");
		return (0);
	}
	if ((*fd = open(av[1], O_RDONLY)) < 3)
		return (0);
	return (1);
}

t_coord			*add_new_element(int x, int y, int z, t_env *e)
{
	t_coord		*newcoord;

	newcoord = (t_coord *)malloc(sizeof(t_coord));
	newcoord->x = x;
	newcoord->y = y;
	newcoord->z = z;
	if (e->xmax < x)
		e->xmax = x;
	if (e->ymax < y)
		e->ymax = y;
	newcoord->next = NULL;
	return (newcoord);
}

t_coord			*lstlast(t_coord *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

static t_coord	**stock_list(t_coord **list, char *line, t_env *e)
{
	static int	y = 0;
	int			i;
	int			x;
	int			z;
	t_coord		*cursor;

	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		z = ft_atoi(&line[i]);
		if (*list)
		{
			cursor = lstlast(*list);
			cursor->next = add_new_element(x, y, z, e);
		}
		else
			*list = add_new_element(x, y, z, e);
		i += ft_intlen(z);
		x++;
	}
	y++;
	return (list);
}

t_coord			*take_map(t_coord **list, int ac, char **av, t_env *e)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	if (!(check_params(ac, av, &fd)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		list = stock_list(list, line, e);
		free(line);
	}
	close(fd);
	return (*list);
}
