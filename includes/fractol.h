/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:43:31 by zweng             #+#    #+#             */
/*   Updated: 2019/02/08 16:03:35 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "ft_mlx.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct  s_env
{
    int         win_width;
    int         win_height;
	t_image		image;
    t_mouse     mouse;
    double      zoom;
    int         iter_max;
    int         fractal;
    void        *mlx;
	void        *win;
}               t_env;

void            ft_draw(t_env *env);
void            ft_mlx_putstr(t_env *env, const char *str, int x, int y);
void	        ft_mlx_putpxl(t_env *env, int x, int y, int color);
void            ft_event(t_env *e);
#endif
