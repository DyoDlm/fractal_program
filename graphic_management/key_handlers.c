/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:40 by aseite            #+#    #+#             */
/*   Updated: 2024/12/19 22:18:41 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	zoom(int key, t_data *d)
{
	if (key == 'x')
	{
		if (d->s.zoom > 0.5)
			d->s.zoom += 0.1;
		else if (d->s.zoom > 0.0000000000001)
			d->s.zoom *= 2;
	}
	if (key == 'z' && d->s.zoom > 0.00000000000001)
	{
		if (d->s.zoom > 0.5)
			d->s.zoom -= 0.1;
		else if (d->s.zoom > 0.0000000000001)
			d->s.zoom /= 2;
	}
	if (key == 'z')
		d->s.log_i++;
	if (key == 'x')
		d->s.log_i--;
	fractal_mod(d);
}

static void	move_and_resolution(int key, t_data *data)
{
	if (key == A_UP)
		data->s.my -= data->s.zoom;
	if (key == A_LEFT)
		data->s.mx -= data->s.zoom;
	if (key == A_RIGHT)
		data->s.mx += data->s.zoom;
	if (key == A_DOWN)
		data->s.my += data->s.zoom;
	if (key == 'i' && data->f.m.mi < 500)
		data->f.m.mi += 5;
	if (key == 'u' && data->f.m.mi > 10)
		data->f.m.mi -= 5;
	if (key == 'j')
		data->s.julia_cx += 0.02;
	if (key == 'n')
		data->s.julia_cx -= 0.02;
	if (key == 'k')
		data->s.julia_cy += 0.02;
	if (key == 'm')
		data->s.julia_cy -= 0.02;
	fractal_mod(data);
}

void	check_screen_mode(t_data *d, int key)
{
	if (key == '1')
		d->s.screen_mode = 1;
	if (key == '2')
		d->s.screen_mode = 2;
	if (key == '3')
		d->s.screen_mode = 3;
	if (key == '4')
		d->s.screen_mode = 4;
	if (key == '5')
		d->s.screen_mode = 5;
	if (key == '6')
		d->s.screen_mode = 6;
	if (key == '7')
		d->s.screen_mode = 7;
	if (key == '8')
		d->s.screen_mode = 8;
	if (key == '9')
		d->s.screen_mode = 9;
}

static void	color(int keycode, t_data *d)
{
	if (keycode == 'q' && d->s.disolvant < 100)
		d->s.disolvant += 5;
	if (keycode == 'w' && d->s.disolvant > 10)
		d->s.disolvant -= 5;
	if (keycode == 'o' && d->s.color < 2000)
		d->s.color += 160;
	if (keycode == 'p' && d->s.color > 0)
		d->s.color -= 160;
	fractal_mod(d);
}

void	handle_key_handlers(int key, t_data *data)
{
	if (key == 'z' || key == 'x')
		zoom(key, data);
	if (key == 'i' || key == 'u')
		move_and_resolution(key, data);
	if (key == 'q' || key == 'w' || key == 'p' || key == 'o')
		color(key, data);
	if (key == 'j' || key == 'k' || key == 'n' || key == 'm')
		move_and_resolution(key, data);
	if (key == A_UP || key == A_DOWN || key == A_LEFT || key == A_RIGHT)
		move_and_resolution(key, data);
	if (key == 'a' && data->cs.state == 1)
		display_control_screen(data);
}
