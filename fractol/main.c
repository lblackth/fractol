/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:10 by lblackth          #+#    #+#             */
/*   Updated: 2022/03/27 23:15:33 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	finit(t_fract *f, char *type)
{
	f->max_x = 1;
	f->min_x = -2;
	f->max_y = 1;
	f->min_y = -1;
	f->max_iter = 50;
	f->type = 'm';
	gradinit(f);
	f->rog = 0;
	f->mov = 1;
	if (!ft_strcmp(type, "Julia"))
	{
		f->max_x += 1;
		f->type = 'j';
	}
	if (!ft_strcmp(type, "Ship"))
	{
		f->max_x += 1;
		f->max_y -= 0.5;
		f->min_y -= 0.5;
		f->type = 's';
	}
}

void	refresher(t_env *e)
{
	int			i;
	int			j;
	t_ip		cor;
	static t_dp	cord;

	i = -1;
	if (e->f.mov)
	{
		mlx_mouse_get_pos(e->win, &cor.x, &cor.y);
		cord.x = e->f.min_x + (double)cor.x / 1920 * (e->f.max_x - e->f.min_x);
		cord.y = e->f.min_y + (double)cor.y / 1080 * (e->f.max_y - e->f.min_y);
	}
	while (i++ < 1919)
	{
		j = -1;
		while (j++ < 1079)
		{
			if (e->f.type == 'm')
				m_print(e, i, j);
			else if (e->f.type == 's')
				s_print(e, i, j);
			else if (e->f.type == 'j')
				j_print(e, i, j, cord);
		}
	}
}

int	render(t_env *e)
{
	e->data.img = mlx_new_image(e->mlx, 1920, 1080);
	e->data.addr = mlx_get_data_addr(e->data.img, \
	&(e->data.bits_per_pixel), &(e->data.line_length), &(e->data.endian));
	refresher(e);
	mlx_put_image_to_window(e->mlx, e->win, e->data.img, 0, 0);
	mlx_destroy_image(e->mlx, e->data.img);
	return (0);
}

int	e_exit(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot") || !ft_strcmp(argv[1], "Julia")
			|| !ft_strcmp(argv[1], "Ship"))
		{
			e.mlx = mlx_init();
			e.win = mlx_new_window(e.mlx, 1920, 1080, "fractol");
			finit(&e.f, argv[1]);
			mlx_loop_hook(e.mlx, &loop_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			write(1, "Available fractols:\n-Mandelbrot\n-Julia\n-Ship\n", 46);
	}
	else
		write(1, "Available fractols:\n-Mandelbrot\n-Julia\n-Ship\n", 46);
	return (0);
}
