/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:53:36 by lblackth          #+#    #+#             */
/*   Updated: 2022/03/12 17:35:30 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_down(int x, int y, t_fract *f)
{
	double	a;
	double	b;
	double	temp;

	a = x / 1920.0;
	b = y / 1080.0;
	temp = (f->max_x - f->min_x) * a * 0.15;
	f->max_x -= (f->max_x - f->min_x) * (1.0 - a) * 0.15;
	f->min_x += temp;
	temp = (f->max_y - f->min_y) * b * 0.15;
	f->max_y -= (f->max_y - f->min_y) * (1.0 - b) * 0.15;
	f->min_y += temp;
}

void	scroll_up(int x, int y, t_fract *f)
{
	double	a;
	double	b;
	double	temp;

	a = x / 1920.0;
	b = y / 1080.0;
	temp = (f->max_x - f->min_x) * a * 0.15;
	f->max_x += (f->max_x - f->min_x) * (1.0 - a) * 0.15;
	f->min_x -= temp;
	temp = (f->max_y - f->min_y) * b * 0.15;
	f->max_y += (f->max_y - f->min_y) * (1.0 - b) * 0.15;
	f->min_y -= temp;
}

int	ud_key(int boutton, t_env *e)
{
	double	temp;

	temp = 0.1 * (e->f.max_y - e->f.min_y);
	if (boutton == 126)
		temp *= -1;
	e->f.max_y += temp;
	e->f.min_y += temp;
	return (0);
}

int	lr_key(int boutton, t_env *e)
{
	double	temp;

	temp = 0.1 * (e->f.max_x - e->f.min_x);
	if (boutton == 123)
		temp *= -1;
	e->f.max_x += temp;
	e->f.min_x += temp;
	return (0);
}
