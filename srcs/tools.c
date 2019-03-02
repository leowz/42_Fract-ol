/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:59:02 by zweng             #+#    #+#             */
/*   Updated: 2019/03/02 15:07:59 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_putstr(t_env *env, const char *str, int x, int y)
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

t_data	ft_change_coordinate_x(t_env *env, int pos)
{
	t_data	ret;

	if (!env || pos < 0 || pos > env->win_width || pos > env->win_height)
		return (0.0);
	ret = (pos - env->win_width / 2.0) * (env->zoom / 1000) + env->center_x;
	return (ret);
}

t_data	ft_change_coordinate_y(t_env *env, int pos)
{
	t_data	ret;

	if (!env || pos < 0 || pos > env->win_width || pos > env->win_height)
		return (0.0);
	ret = (env->win_height / 2.0 - pos) * (env->zoom / 1000) + env->center_y;
	return (ret);
}
