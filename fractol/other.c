/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblackth <lblackth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:06:32 by lblackth          #+#    #+#             */
/*   Updated: 2022/02/26 17:06:43 by lblackth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	gradinit(t_fract *f)
{
	f->gradr = (int *)malloc(sizeof(int) * 3);
	f->gradg = (int *)malloc(sizeof(int) * 6);
	f->gradr[0] = 0xff0000;
	f->gradr[1] = 0xffffff;
	f->gradr[2] = 0x0000ff;
	f->gradg[0] = 0x800080;
	f->gradg[1] = 0xff0000;
	f->gradg[2] = 0xff8000;
	f->gradg[3] = 0xffff00;
	f->gradg[4] = 0x009900;
	f->gradg[5] = 0x0000bb;
}
