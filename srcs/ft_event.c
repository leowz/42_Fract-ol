/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:53:35 by zweng             #+#    #+#             */
/*   Updated: 2019/03/02 15:08:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"

int		hook_mousedown(int button, int x, int y, t_env *env)
{
	if (x < 0 || y < 0 || x > env->win_width || y > env->win_height)
		return (0);
	if (button == SCROLLUP_KEY || button == SCROLLDOWN_KEY)
	{
		if (button == SCROLLUP_KEY)
			env->zoom /= (env->zoom_rate);
		else if (button == SCROLLDOWN_KEY)
			env->zoom *= (env->zoom_rate);
		if (env->zoom < ZOOM_MIN)
			env->zoom = ZOOM_MIN;
		else if (env->zoom >= 4)
		{
			env->zoom = 4;
			env->center_x = 0.0;
			env->center_y = 0.0;
		}
		else
		{
			env->center_x = ft_change_coordinate_x(env, env->mouse.x);
			env->center_y = ft_change_coordinate_y(env, env->mouse.y);
		}
	}
	ft_draw(env);
	return (0);
}

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
	ft_draw(env);
	return (0);
}

int		hook_key(int key, t_env *env)
{
	(void)env;
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (key == R_KEY)
	{
		env->center_x = 0;
		env->center_y = 0;
		env->zoom = 4.0;
	}
	ft_draw(env);
	return (0);
}

void	ft_event(t_env *e)
{
	mlx_key_hook(e->win, hook_key, e);
	mlx_hook(e->win, 4, 0, hook_mousedown, e);
	mlx_hook(e->win, 6, 0, hook_mousemove, e);
}
