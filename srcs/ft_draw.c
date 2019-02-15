/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:22:49 by zweng             #+#    #+#             */
/*   Updated: 2019/02/15 17:54:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandelbrot(t_env *env, int pos_x, int pos_y)
{
    // normalize coordinate
    double  c_r = ft_change_coordinateX(env, pos_x);
    double  c_i = ft_change_coordinateY(env, pos_y);
    double  z_r = 0;
    double  z_i = 0;
    int     iter = 80;
    double  tmp;
    
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
    double  c_r = (env->mouse.x - env->win_width / 2) * (4.0 ) / ( 1000 );
    double  c_i = (env->mouse.y - env->win_height / 2) * (4.0 ) / ( 1000 );
    double  z_r = (pos_x - env->win_width / 2) * (4.0 ) / ( 1000 );
    double  z_i = (pos_y - env->win_height / 2) * (4.0 ) / ( 1000 );
    int     iter = 50;
    double  tmp;
    
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


void    *ft_mt(void *arg)
{
    int     i_x;
    int     i_y;
    int     l_x;
    int     l_y;
    t_mt    *mt = (t_mt *)arg;

    i_y = mt->zone < 2 ? 0 : mt->env->win_height / 2;
    l_y = mt->zone < 2 ? mt->env->win_height / 2 : mt->env->win_height;
    while (i_y < l_y)
    {
        i_x = (mt->zone % 2) ? mt->env->win_width / 2 : 0;
        l_x = (mt->zone % 2) ? mt->env->win_width : mt->env->win_width / 2;
        while (i_x < l_x)
        {
            if (mt->env->fractal == 1)
               draw_mandelbrot(mt->env, i_x, i_y);
            else if(mt->env->fractal == 2)
               draw_julia(mt->env, i_x, i_y);
            i_x++;
        }
        i_y++;
    }
    return (NULL);
}

void    ft_draw(t_env *env)
{
    pthread_t   thread_id[4];
    t_mt        mt[4];
    int         i;

    i = 0;
    while (i < 4)
    {
        mt[i].env = env;
        mt[i].zone = i;
        pthread_create(&(thread_id[i]), NULL, ft_mt, &(mt[i]));
        i++;
    }
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_join(thread_id[2], NULL);
    pthread_join(thread_id[3], NULL);
    mlx_clear_window(env->mlx, env->win);
    mlx_put_image_to_window(env->mlx, env->win, env->image.img_ptr, 0, 0);
}
