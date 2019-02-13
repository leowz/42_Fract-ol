/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:41:58 by zweng             #+#    #+#             */
/*   Updated: 2019/02/13 18:38:42 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"
# define ZR (1.5)

int		hook_mousedown(int button, int x, int y, t_env *env)
{
    printf("mouse down called %d\n", button);
	if (x < 0 || y < 0 || x > env->win_width || y > env->win_height)
		return (0);
	if (button == BUT1_KEY || button == BUT2_KEY)
		env->mouse.isdown = button;
	if (button == SCROLLUP_KEY)
	{
        printf("scroll up\n");
        env->centerX = ft_change_coordinateX(env, env->mouse.x);
        env->centerY = ft_change_coordinateY(env, env->mouse.y);
		env->zoom /= (ZR);
		if (env->zoom > 4)
            env->zoom = 4;
	}
	if (button == SCROLLDOWN_KEY)
	{
        printf("scroll down\n");
        env->centerX = ft_change_coordinateX(env, env->mouse.x);
        env->centerY = ft_change_coordinateY(env, env->mouse.y);
		env->zoom *= (ZR);
		if (env->zoom < 0)
            env->zoom = 0;
	}
    ft_draw(env);
	return (0);
}

/*int		hook_mouseup(int button, int x, int y, t_mlx_data *mlx)
{
	(void)button;
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return (0);
	mlx->mouse.isdown = 0;
	return (0);
}*/

int		hook_mousemove(int x, int y, t_env *env)
{
	if (x < 0 || y < 0 || x >= env->win_width || y >= env->win_height)
	{
		env->mouse.isdown = 0;
		return (0);
	}
	env->mouse.lastx = env->mouse.x;
	env->mouse.lasty = env->mouse.y;
	env->mouse.x = x;
	env->mouse.y = y;
       // env->centerX = ft_change_coordinateX(env, env->mouse.x);
        //env->centerY = ft_change_coordinateY(env, env->mouse.y);
    printf("center x (%f) y (%f)\n", env->centerX, env->centerY);
    ft_draw(env);
	return (0);
}

int		hook_key(int key, t_env *env)
{
    (void)env;
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
    else if (key == Z_KEY)
    {
        env->centerX = ft_change_coordinateX(env, env->mouse.x);
        env->centerY = ft_change_coordinateY(env, env->mouse.y);
        env->zoom /= 1.5; 
        printf("center x (%f) y (%f)\n", env->centerX, env->centerY);
    }
    else if (key == R_KEY)
    {
        env->centerX = 0;
        env->centerY = 0;
        env->zoom = 4.0;
    }
    ft_draw(env);
	return (0);
}

void    ft_event(t_env *e)
{
    mlx_key_hook(e->win, hook_key, e);
	mlx_hook(e->win, 4, 0, hook_mousedown, e);
//	mlx_hook(env->win, 5, 0, hook_mouseup, e);
	mlx_hook(e->win, 6, 0, hook_mousemove, e);
}
