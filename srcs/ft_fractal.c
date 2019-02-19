/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:05:08 by zweng             #+#    #+#             */
/*   Updated: 2019/02/19 12:17:00 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandelbrot(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    t_data  c_r = ft_change_coordinateX(env, pos_x);
    t_data  c_i = ft_change_coordinateY(env, pos_y);
    t_data  z_r = 0;
    t_data  z_i = 0;
    int     iter = 80;
    t_data  tmp;
    
    int     i = 0;
    while (z_r * z_r + z_i * z_i < 4 && i < iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == iter)
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
    else
        ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (iter));
}

void    draw_julia(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    t_data  c_r = (env->mouse.x - env->win_width / 2) * (4.0 ) / ( 1000 );
    t_data  c_i = (env->mouse.y - env->win_height / 2) * (4.0 ) / ( 1000 );
    t_data  z_r = (pos_x - env->win_width / 2) * (4.0 ) / ( 1000 );
    t_data  z_i = (pos_y - env->win_height / 2) * (4.0 ) / ( 1000 );
    int     iter = 50;
    t_data  tmp;
    
    int     i = 0;
    while (z_r * z_r + z_i * z_i < 4 && i < iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
    }
    if (i == iter)
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
    else
        ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (iter));
}

void    draw_burningship(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    t_data  c_r = ft_change_coordinateX(env, pos_x);
    t_data  c_i = ft_change_coordinateY(env, pos_y);
    t_data  z_r = 0;
    t_data  z_i = 0;
    int     iter = 50;
    t_data  tmp;
    
    int     i = 0;
    while (z_r * z_r + z_i * z_i < 4 && i < iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * fabsl(z_i * tmp) + c_i;
        i++;
    }
    if (i == iter)
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
    else
        ft_mlx_putpxl(env, pos_x, pos_y, (i * COLOR_WHITE) / (iter));
}
