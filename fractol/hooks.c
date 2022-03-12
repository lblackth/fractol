/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:49:21 by lblackth          #+#    #+#             */
/*   Updated: 2022/03/12 18:48:40 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int btn, t_env *e)
{
	if (btn == 123 || btn == 124)
		lr_key(btn, e);
	else if (btn == 125 || btn == 126)
		ud_key(btn, e);
	else if (btn == 40)
		e->f.rog = !e->f.rog;
	else if (btn == 69)
		e->f.max_iter++;
	else if (btn == 78)
		e->f.max_iter--;
	else if (btn == 53)
		e_exit(e);
	return (0);
}

int	mouse_hook(int btn, int x, int y, t_fract *f)
{
	if (btn == 5)
		scroll_down(x, y, f);
	else if (btn == 4)
		scroll_up(x, y, f);
	else if (btn == 1)
		f->mov = !f->mov;
	return (0);
}

int	loop_hook(t_env *e)
{
	render(e);
	mlx_key_hook(e->win, &key_hook, e);
	mlx_mouse_hook(e->win, &mouse_hook, &e->f);
	return (0);
}
