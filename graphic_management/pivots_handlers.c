/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:48 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:33:30 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	close_win(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_to_go(data, '0');
	exit(EXIT_SUCCESS);
	return (0);
}

static void	display(t_data *data, int kc)
{
	check_screen_mode(data, kc);
	mlx_clear_window(data->mlx, data->win);
	if (kc == 49)
		display_mandelbrot(data);
	else if (kc == 50)
		display_julia(data);
	else if (kc == 51)
		display_newton(data);
	else if (kc == 52)
		display_exit_message(data);
	else
		display_home(data);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_win(data);
	if (keycode == 's' || (keycode == 'h' || (keycode <= '9' && keycode >= 0)))
		display(data, keycode);
	if (keycode == 's')
		fractal_mod(data);
	if (keycode == 'r')
	{
		free_to_go(data, '1');
		init_data(data, '1');
		mlx_clear_window(data->mlx, data->win);
		display_exit_message(data);
		data->cs.state = 0;
	}
	if (keycode == 'c' && data->cs.state != 1)
	{
		data->cs.state = 1;
		display_control_screen(data);
	}
	handle_key_handlers(keycode, data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	data->s.julia_cx = x;
	data->s.julia_cy = y;
	fractal_mod(data);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		d->s.zoom /= 1.1;
	}
	else if (button == 5)
	{
		d->s.zoom *= 1.1;
	}
	else if (button == 2)
		d->s.color += WHITE / 10;
	else if (button == 1)
		d->s.color -= WHITE / 10;
	fractal_mod(d);
	return (1);
}
