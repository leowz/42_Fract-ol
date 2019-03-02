/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:58:05 by zweng             #+#    #+#             */
/*   Updated: 2019/03/02 15:02:14 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_env *env, int pos_x, int pos_y)
{
	t_data	c[2];
	t_data	z[2];
	t_data	tmp;
	int		i;

	i = 0;
	c[0] = ft_change_coordinate_x(env, pos_x);
	c[1] = ft_change_coordinate_y(env, pos_y);
	z[0] = 0;
	z[1] = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	if (i == env->iter)
		ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
	else
		ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (env->iter));
}

void	draw_julia(t_env *env, int pos_x, int pos_y)
{
	t_data	c[2];
	t_data	z[2];
	t_data	tmp;
	int		i;

	i = 0;
	c[0] = ft_change_coordinate_x(env, env->mouse.x);
	c[1] = ft_change_coordinate_y(env, env->mouse.y);
	z[0] = ft_change_coordinate_x(env, pos_x);
	z[1] = ft_change_coordinate_y(env, pos_y);
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	if (i == env->iter)
		ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
	else
		ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (env->iter));
}

void	draw_burningship(t_env *env, int pos_x, int pos_y)
{
	t_data	c[2];
	t_data	z[2];
	t_data	tmp;
	int		i;

	i = 0;
	c[0] = ft_change_coordinate_x(env, pos_x);
	c[1] = ft_change_coordinate_y(env, pos_y);
	z[0] = 0;
	z[1] = 0;
	while (z[0] * z[0] + z[1] * z[1] < 4 && i < env->iter)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * fabsl(z[1] * tmp) + c[1];
		i++;
	}
	if (i == env->iter)
		ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
	else
		ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (env->iter));
}
