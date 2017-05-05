/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:32 by jichen-m          #+#    #+#             */
/*   Updated: 2017/05/05 18:24:20 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_coord(t_coord **list, t_env *e)
{
	int tmp1;
	int tmp2;

	(*list)->x2 = (*list)->x * e->scale - (e->scale * e->xmax / 2);
	(*list)->y2 = (*list)->y * e->scale - (e->scale * e->ymax / 2);
	tmp1 = (*list)->x2 * cos(e->angle) - (*list)->y2 * sin(e->angle);
	tmp2 = (*list)->x2 * sin(e->angle) + (*list)->y2 * cos(e->angle);
	(*list)->x2 = tmp1 + e->x + (e->scale * 10);
	(*list)->y2 = tmp2 + e->y + (e->scale * 10);
	if ((*list)->z > 0)
		(*list)->y2 -= e->scale * (*list)->z / 10;
	(*list)->y2 -= e->scale / 2 * (*list)->y;
	(*list)->x2 -= ((*list)->y * e->scale / 4);
	(*list)->y2 += ((*list)->y * e->scale / 4);
}

int		ft_intlen(int nbr)
{
	int	ret;

	ret = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		ret++;
	}
	while (nbr /= 10)
		ret++;
	return (ret);
}

t_env	*init_env(t_env *e)
{
	e->scale = 30;
	e->x = e->scale * 20;
	e->y = e->scale * 10;
	e->xmax = 0;
	e->ymax = 0;
	e->angle = 0.60;
	return (e);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_coord	*map;

	map = NULL;
	init_env(&e);
	if (!(e.mlx = mlx_init())
		|| !(e.win = mlx_new_window(e.mlx, 1000, 1000, "FDF"))
		|| !(e.map = take_map(&map, ac, av, &e)))
		return (0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
