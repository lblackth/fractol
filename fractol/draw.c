/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:03:59 by lblackth          #+#    #+#             */
/*   Updated: 2022/03/12 17:35:30 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print(t_env *e, double iter, int i, int j)
{
	if (!e->f.rog)
	{
		if (iter < e->f.max_iter)
			my_mlx_pixel_put(&e->data, i, j, e->f.gradg[(int)iter % 6]);
		else
			my_mlx_pixel_put(&e->data, i, j, 0x0);
	}
	else
	{
		if (iter < e->f.max_iter)
			my_mlx_pixel_put(&e->data, i, j, e->f.gradr[(int)iter % 3]);
		else
			my_mlx_pixel_put(&e->data, i, j, 0x0);
	}
}

void	m_print(t_env *e, int i, int j)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = e->f.min_x + (double)i / 1920 * (e->f.max_x - e->f.min_x);
	con.y = e->f.min_y + (double)j / 1080 * (e->f.max_y - e->f.min_y);
	def.x = 0;
	def.y = 0;
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < e->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = 2 * def.x * def.y + con.y;
		def.x = temp;
		iter++;
	}
	print(e, iter, i, j);
}

void	j_print(t_env *e, int i, int j, t_dp cord)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = cord.x;
	con.y = cord.y;
	def.x = e->f.min_x + (double)i / 1920 * (e->f.max_x - e->f.min_x);
	def.y = e->f.min_y + (double)j / 1080 * (e->f.max_y - e->f.min_y);
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < e->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = 2 * def.x * def.y + con.y;
		def.x = temp;
		iter++;
	}
	print(e, iter + 1, i, j);
}

void	s_print(t_env *e, int i, int j)
{
	double	temp;
	t_dp	def;
	t_dp	con;
	double	iter;

	con.x = e->f.min_x + (double)i / 1920 * (e->f.max_x - e->f.min_x);
	con.y = e->f.min_y + (double)j / 1080 * (e->f.max_y - e->f.min_y);
	def.x = 0;
	def.y = 0;
	iter = 0;
	while (def.x * def.x + def.y * def.y < 4 && iter < e->f.max_iter)
	{
		temp = def.x * def.x - def.y * def.y + con.x;
		def.y = fabs(2 * def.x * def.y) + con.y;
		def.x = temp;
		iter++;
	}
	print(e, iter, i, j);
}
