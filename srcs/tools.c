/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:55:34 by zweng             #+#    #+#             */
/*   Updated: 2019/02/13 18:26:36 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_mlx_putstr(t_env *env, const char *str, int x, int y)
{
    if (!env || !str)
        return ;
    mlx_string_put(env->mlx, env->win, x, y, COLOR_WHITE, (char *)str);
}

void	ft_mlx_putpxl(t_env *env, int x, int y, int color)
{
    t_image *img;

    if (!env)
        return ;
	if (x <= 0 || x >= env->win_width || y <= 0 || y >= env->win_height)
		return ;
    img = &(env->image);
	*((int *)(img->buf_ptr + ((x + y * env->win_width) * img->bpp))) = color;
}

double  ft_change_coordinateX(t_env *env, int pos)
{
    double  ret;

    if (!env || pos < 0 || pos > env->win_width || pos > env->win_height)
        return (0.0);
    ret = (pos - env->win_width / 2.0) * (env->zoom / 1000) + env->centerX;
    return (ret);
}

double  ft_change_coordinateY(t_env *env, int pos)
{
    double  ret;

    if (!env || pos < 0 || pos > env->win_width || pos > env->win_height)
        return (0.0);
    ret = (env->win_height / 2.0 - pos) * (env->zoom / 1000) + env->centerY;
    return (ret);
}
