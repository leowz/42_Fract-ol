/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <zweng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:10:26 by zweng             #+#    #+#             */
/*   Updated: 2019/03/02 15:10:28 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractal(t_env *env, const char *fractal)
{
	if (fractal && !(ft_strcmp(fractal, "mandelbrot")))
		env->fractal = 1;
	else if (fractal && !(ft_strcmp(fractal, "julia")))
		env->fractal = 2;
	else if (fractal && !(ft_strcmp(fractal, "burningship")))
		env->fractal = 3;
	else
		return (FALSE);
	return (TRUE);
}

static void	init_env(t_env *env)
{
	t_image		*image;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1000, 1000, "Fract'ol");
	env->win_width = 1000;
	env->win_height = 1000;
	env->zoom = 4.0;
	env->zoom_rate = 1.5;
	env->center_x = 0.0;
	env->center_y = 0.0;
	env->iter = 80;
	image = &(env->image);
	image->img_ptr = mlx_new_image(env->mlx, 1000, 1000);
	image->buf_ptr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
					&(image->size_line), &(image->endian));
	image->bpp /= 8;
}

static void	print_usage(void)
{
	ft_printf("usage: fractol [ mandelbrot | julia | burningship ]\n");
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && init_fractal(&e, av[1]))
	{
		init_env(&e);
		ft_draw(&e);
		ft_event(&e);
		mlx_loop(e.mlx);
	}
	else
		print_usage();
	return (0);
}
