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

static void	init_1(t_mt *mt, int *i, int *l)
{
	if (mt->zone < 2)
	{		
		i[1] = 0;
		l[1] = mt->env->win_height / 2;
	}
	else
	{
		i[1] = mt->env->win_height / 2;
		l[1] = mt->env->win_height; 
	}
}

static void	init_2(t_mt *mt, int *i, int *l)
{
	if (mt->zone % 2)
	{
		i[0] = mt->env->win_width / 2;	
		l[0] = mt->env->win_width;
	}
	else
	{	
		i[0] = 0;
		l[0] = mt->env->win_width / 2;
	}
}

void	*ft_mt(void *arg)
{
	int		i[2];
	int		l[2];
	t_mt	*mt;

	mt = (t_mt *)arg;
	init_1(mt, i, l);
	while (i[1] < l[1])
	{
		init_2(mt, i, l);
		while (i[0] < l[0])
		{
			if (mt->env->fractal == 1)
				draw_mandelbrot(mt->env, i[0] , i[1]);
			else if(mt->env->fractal == 2)
				draw_julia(mt->env, i[0], i[1]);
			else if(mt->env->fractal == 3)
				draw_burningship(mt->env, i[0], i[1]);
			i[0]++;
		}
		i[1]++;
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
