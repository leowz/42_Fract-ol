/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_draw.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: zweng <zweng@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2019/02/06 11:22:49 by zweng			   #+#	  #+#			  */
/*	 Updated: 2019/02/19 18:52:05 by zweng			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_mt(void *arg)
{
	int		i_x;
	int		i_y;
	int		l_x;
	int		l_y;
	t_mt	*mt = (t_mt *)arg;

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
			else if(mt->env->fractal == 3)
				draw_burningship(mt->env, i_x, i_y);
			i_x++;
		}
		i_y++;
	}
	return (NULL);
}

void	ft_draw(t_env *env)
{
	pthread_t	thread_id[4];
	t_mt		mt[4];
	int			i;

	i = 0;
	while (i < 4)
	{
		mt[i].env = env;
		mt[i].zone = i;
		pthread_create(&(thread_id[i]), NULL, ft_mt, &(mt[i]));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->image.img_ptr, 0, 0);
}
