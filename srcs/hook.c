/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:32 by jichen-m          #+#    #+#             */
/*   Updated: 2016/02/07 05:24:35 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*lstprev(t_coord *beginlist, t_coord *list)
{
	t_coord	*cursor;

	cursor = beginlist;
	while (cursor)
	{
		if (cursor->y == list->y - 1 && cursor->x == list->x)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void	print_grid(t_env *e)
{
	t_coord	*cursor;
	t_coord	*cursorup;

	cursor = e->map;
	cursorup = NULL;
	while (cursor)
	{
		if (cursor->next && cursor->next->y == cursor->y)
			draw_line(e, cursor, cursor->next);
		if ((cursorup = lstprev(e->map, cursor)))
			draw_line(e, cursor, cursorup);
		cursor = cursor->next;
	}
}

void	add_movement(t_env *e)
{
	t_coord	*cursor;

	cursor = e->map;
	while (cursor)
	{
		put_coord(&cursor, e);
		cursor = cursor->next;
	}
}

int		expose_hook(t_env *e)
{
	add_movement(e);
	mlx_clear_window(e->mlx, e->win);
	print_grid(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
		e->y -= e->scale;
	if (keycode == 125)
		e->y += e->scale;
	if (keycode == 123)
		e->x -= e->scale;
	if (keycode == 124)
		e->x += e->scale;
	if (keycode == 30)
		if (e->scale < 100)
			e->scale += 1;
	if (keycode == 44)
		if (e->scale > 1)
			e->scale -= 1;
	if (keycode == 2)
		if (e->angle < 6.3)
			e->angle += 0.1;
	if (keycode == 0)
		if (e->angle > -6.15)
			e->angle -= 0.1;
	expose_hook(e);
	return (0);
}
