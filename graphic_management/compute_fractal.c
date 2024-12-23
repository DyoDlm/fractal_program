/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:17:49 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 16:24:51 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static int	paint_nova(t_data *d, t_build *b)
{
	t_derive	f;
	double		module;
	double		denominateur;

	if (d->s.screen_mode == 3)
	{
		b->tp = b->zx;
		b->tp2 = b->zy;
		f.fr_one = b->zx * b->zx * b->zx - 3 * b->zx * b->zy * b->zy - 1;
		f.fi_one = 3 * b->zx * b->zx * b->zy - b->zy * b->zy * b->zy;
		f.fr_two = 3 * (b->zx * b->zx - b->zy * b->zy);
		f.fi_two = 6 * b->zx * b->zy;
		denominateur = (f.fr_two * f.fr_two) + (f.fi_two * f.fi_two);
		if (denominateur == 0.0)
			return (0);
		f.incr_re = (f.fr_one * f.fr_two + f.fi_one * f.fi_two) / denominateur;
		f.incr_im = (f.fi_one * f.fr_two - f.fr_one * f.fi_two) / denominateur;
		b->zx = b->zx - f.incr_re;
		b->zy = b->zy - f.incr_im;
		module = (f.incr_re * f.incr_re) + (f.incr_im * f.incr_im);
		if (module < 0.000001)
			return (-1);
	}
	return (1);
}

void	compute_czxy(t_data *d, t_build *b, int *i)
{
	double	q;

	q = d->s.zoom;
	if (d->s.screen_mode == 1)
	{
		b->cx = ((b->x - d->s.wi / 2.0) * 4.0 / d->s.wi) * q + d->s.mx;
		b->cy = ((b->y - d->s.hi / 2.0) * 4.0 / d->s.hi) * q + d->s.my;
		b->zx = 0;
		b->zy = 0;
	}
	if (d->s.screen_mode == 3 || d->s.screen_mode == 4)
	{
		b->zx = 1.5 * (b->x - d->s.wi / 2) / (0.5 / q * d->s.wi) + d->s.mx;
		b->zy = (b->y - d->s.hi / 2) / (0.5 / q * d->s.hi) + d->s.my;
	}
	if (d->s.screen_mode == 2)
	{
		b->zx = 1.5 * (b->x - d->s.wi / 2) / (0.5 / q * d->s.wi) + d->s.mx;
		b->zy = (b->y - d->s.hi / 2) / (0.5 / q * d->s.hi) + d->s.my;
	}
	*i = 0;
}

int	check_limits(t_data *d, t_build *b, int *i)
{
	if (b->zx * b->zx + b->zy * b->zy < 4.0 && *i < d->f.m.mi)
		return (1);
	return (0);
}

int	paint_x_axis(t_data *d, t_build *b, int *i)
{
	if (d->s.screen_mode == 1)
	{
		b->tp = b->zx * b->zx - b->zy * b->zy + b->cx;
		b->zy = 2.0 * b->zx * b->zy + b->cy;
		b->zx = b->tp;
	}
	if (d->s.screen_mode == 2)
	{
		b->tp = b->zx * b->zx - b->zy * b->zy + d->s.julia_cx;
		b->zy = 2.0 * b->zx * b->zy + d->s.julia_cy;
		b->zx = b->tp;
	}
	if (d->s.screen_mode == 3)
		if (paint_nova(d, b) == -1)
			return (0);
	if (d->s.screen_mode == 4)
		(void)b;
	*i += 1;
	return (1);
}

void	map_pixel(t_data *d, t_build *b, int color)
{
	int	ok;

	ok = 0;
	if (b->x >= 0 && b->x < d->s.wi && b->y >= 0 && b->y < d->s.hi)
		ok = 1;
	if (ok != 1)
		return ;
	if (d->s.screen_mode == 1)
	{
		d->f.m.pindex = b->y * d->f.m.l + b->x * (d->f.m.b / 8);
		*(int *)(d->f.m.a + d->f.m.pindex) = color;
	}
	if (d->s.screen_mode == 2)
	{
		d->f.j.pindex = b->y * d->f.j.l + b->x * (d->f.j.b / 8);
		*(int *)(d->f.j.a + d->f.j.pindex) = color;
	}
	if (d->s.screen_mode == 3 || d->s.screen_mode == 4)
	{
		d->f.n.pindex = b->y * d->f.n.l + b->x * (d->f.n.b / 8);
		*(int *)(d->f.n.a + d->f.n.pindex) = color;
	}
}
