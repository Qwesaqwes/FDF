/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:21:51 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/03 18:08:43 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 50000
# define MAX_BUF 1000000000
# define UP_COLOR 0x00FF00
# define MID_COLOR 0xFF6600
# define DOWN_COLOR 0xFFFFFF

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				x2;
	int				y2;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_coord			*map;
	double			angle;
	int				scale;
	int				x;
	int				y;
	int				xmax;
	int				ymax;
}					t_env;

void				put_coord(t_coord **list, t_env *e);
void				draw_line(t_env *e, t_coord *pt1, t_coord *pt2);
int					get_next_line(int const fd, char **line);
int					ft_intlen(int nbr);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
t_coord				*take_map(t_coord **list, int ac, char **av, t_env *e);

#endif
