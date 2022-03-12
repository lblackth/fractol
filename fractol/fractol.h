/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:08:10 by lblackth          #+#    #+#             */
/*   Updated: 2022/03/12 18:20:09 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fract
{
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	max_iter;
	char	type;
	int		*gradg;
	int		*gradr;
	int		rog;
	int		mov;
}				t_fract;

typedef struct s_env
{
	void	*win;
	void	*mlx;
	t_data	data;
	t_fract	f;
}				t_env;

typedef struct s_dp
{
	double	x;
	double	y;
}				t_dp;

typedef struct s_ip
{
	int	x;
	int	y;
}				t_ip;

int		ft_strcmp(const char *s1, const char *s2);
void	gradinit(t_fract *f);
void	finit(t_fract *f, char *type);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print(t_env *e, double iter, int i, int j);
void	m_print(t_env *e, int i, int j);
void	j_print(t_env *e, int i, int j, t_dp cord);
void	s_print(t_env *e, int i, int j);
void	refresher(t_env *e);
int		render(t_env *e);
int		e_exit(t_env *e);
int		lr_key(int btn, t_env *e);
int		ud_key(int btn, t_env *e);
int		key_hook(int btn, t_env *e);
void	scroll_down(int x, int y, t_fract *f);
void	scroll_up(int x, int y, t_fract *f);
int		mouse_hook(int btn, int x, int y, t_fract *f);
int		loop_hook(t_env *e);
int		main(int argc, char **argv);

#endif
