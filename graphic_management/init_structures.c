/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:26 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 13:09:25 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	init_julia(t_data *data)
{
	data->f.j.img = NULL;
	data->f.j.a = NULL;
	data->f.j.b = 0;
	data->f.j.l = 0;
	data->f.j.e = 0;
	data->f.m.mi = 100;
	data->f.j.pindex = 0;
}

void	init_newton(t_data *data)
{
	data->f.n.img = NULL;
	data->f.n.a = NULL;
	data->f.n.b = 0;
	data->f.n.l = 0;
	data->f.n.e = 0;
	data->f.m.mi = 10;
	data->f.n.pindex = 0;
}

void	init_mandelbrot(t_data *data)
{
	data->f.m.img = NULL;
	data->f.m.a = NULL;
	data->f.m.b = 0;
	data->f.m.l = 0;
	data->f.m.e = 0;
	data->f.m.mi = 10;
	data->f.m.pindex = 0;
	data->s.disolvant = 30;
}

void	init_build(t_build *data)
{
	data->tp = 0;
	data->tp2 = 0;
	data->zx = 0;
	data->zy = 0;
	data->cx = 0;
	data->cy = 0;
	data->x = 0;
	data->y = 0;
}

void	init_control_screen(t_data *data)
{
	data->cs.state = 0;
	data->cs.l = 0;
	data->cs.a = NULL;
	data->cs.img = NULL;
	data->cs.b = 0;
	data->cs.e = 0;
	data->cs.info.content = NULL;
}
