/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:22:49 by zweng             #+#    #+#             */
/*   Updated: 2019/02/08 17:42:31 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandelbrot(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    double  c_r = (pos_x - env->win_width / 2) * (4.0 ) / ( 1000 );
    double  c_i = (pos_y - env->win_height / 2) * (4.0 ) / ( 1000 );
    double  z_r = 0;
    double  z_i = 0;
    int     iter = 50;
    double  tmp;
    
    int     i = 0;
    while (i < iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
        if (z_r * z_r + z_i * z_i > 4)
        {
            ft_mlx_putpxl(env, pos_x, pos_y, COLOR_WHITE);
            return ;
        }
    }
    if (z_r * z_r + z_i * z_i < 4)
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
    else
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_WHITE);
}

void    draw_julia(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    double  c_r = (env->mouse.x - env->win_width / 2) * (4.0 ) / ( 1000 );
    double  c_i = (env->mouse.y - env->win_height / 2) * (4.0 ) / ( 1000 );
    double  z_r = (pos_x - env->win_width / 2) * (4.0 ) / ( 1000 );
    double  z_i = (pos_y - env->win_height / 2) * (4.0 ) / ( 1000 );
    int     iter = 50;
    double  tmp;
    
    int     i = 0;
    while (i < iter)
    {
        tmp = z_r;
        z_r = z_r * z_r - z_i * z_i + c_r;
        z_i = 2 * z_i * tmp + c_i;
        i++;
        if (z_r * z_r + z_i * z_i > 4)
        {
            ft_mlx_putpxl(env, pos_x, pos_y, COLOR_WHITE);
            return ;
        }
    }
    if (z_r * z_r + z_i * z_i < 4)
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_BLACK);
    else
        ft_mlx_putpxl(env, pos_x, pos_y, COLOR_WHITE);
}

void    ft_draw(t_env *env)
{
    int     i_x;
    int     i_y;

    i_x = 0;
    while (i_x < 1000)
    {
        i_y = 0;
        while (i_y < 1000)
        {
            if (env->fractal == 1)
               draw_mandelbrot(env, i_x, i_y);
            else if(env->fractal == 2)
               draw_julia(env, i_x, i_y);
            i_y++;
        }
        i_x++;
    }
    mlx_clear_window(env->mlx, env->win);
    mlx_put_image_to_window(env->mlx, env->win, env->image.img_ptr, 0, 0);
}
