/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:41:58 by zweng             #+#    #+#             */
/*   Updated: 2019/02/08 16:33:08 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"

/*int		hook_mousedown(int button, int x, int y, t_env *env)
{
	if (x < 0 || y < 0 || x > env->win_width || y > env->win_height)
		return (FALSE);
	if (button == BUT1_KEY || button == BUT2_KEY)
		mlx->mouse.isdown = button;
	if (button == SCROLLUP_KEY)
	{
		mlx->cam.scale += 2;
		if (mlx->cam.scale > (MAX_SCALE * mlx->cam.def_scale))
			mlx->cam.scale = (MAX_SCALE * mlx->cam.def_scale);
		else
			fx_render(mlx);
		return (FALSE);
	}
	if (button == SCROLLDOWN_KEY)
	{
		mlx->cam.scale -= 2;
		if (mlx->cam.scale < 2)
			mlx->cam.scale = 2;
		else
			fx_render(mlx);
		return (FALSE);
	}
	return (FALSE);
}*/

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
    ft_draw(env);
	return (0);
}

int		hook_key(int key, t_env *env)
{
    (void)env;
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
	return (0);
}

void    ft_event(t_env *e)
{
    mlx_key_hook(e->win, hook_key, e);
//	mlx_hook(env->win, 4, 0, hook_mousedown, e);
//	mlx_hook(env->win, 5, 0, hook_mouseup, e);
	mlx_hook(e->win, 6, 0, hook_mousemove, e);
}
