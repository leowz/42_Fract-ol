/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:55:34 by zweng             #+#    #+#             */
/*   Updated: 2019/02/08 12:38:59 by zweng            ###   ########.fr       */
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
