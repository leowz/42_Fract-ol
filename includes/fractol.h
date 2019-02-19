/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:43:31 by zweng             #+#    #+#             */
/*   Updated: 2019/02/19 18:51:03 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "ft_mlx.h"
# include "libft.h"
# include "ft_printf.h"

typedef long double t_data;

typedef struct      s_mouse
{
	char		    isdown;
	int			    x;
	int			    y;
	int			    lastx;
	int			    lasty;
}				    t_mouse;

typedef struct      s_env
{
    t_data          centerX;
    t_data          centerY;
    int             win_width;
    int             win_height;
	t_image		    image;
    t_mouse         mouse;
    t_data          zoom;
    int             iter_max;
    int             fractal;
    void            *mlx;
	void            *win;
}                   t_env;

typedef struct      s_mt
{
    t_env           *env;
    int             zone;
}                   t_mt;

void                ft_draw(t_env *env);
void                ft_mlx_putstr(t_env *env, const char *str, int x, int y);
void	            ft_mlx_putpxl(t_env *env, int x, int y, int color);
void                ft_event(t_env *e);
t_data              ft_change_coordinateX(t_env *env, int pos);
t_data              ft_change_coordinateY(t_env *env, int pos);
void                draw_mandelbrot(t_env *env, int pos_x, int pos_y);
void                draw_julia(t_env *env, int pos_x, int pos_y);
void                draw_burningship(t_env *env, int pos_x, int pos_y);
#endif
