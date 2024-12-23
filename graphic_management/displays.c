/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:18:08 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 16:20:07 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	display_home(t_data *data)
{
	char	text[51];
	int		color;

	color = RED;
	ft_memset(text, 0, 51);
	ft_memcpy(text, "Hi noob brother ! Click 's' to lauch fractal mode.", 50);
	text[50] = '\0';
	mlx_string_put(data->mlx, data->win, 100, 50, color, text);
	display_redirection(data);
}

void	display_mandelbrot(t_data *data)
{
	char	text[39];
	int		color;

	color = RED;
	ft_memset(text, 0, 39);
	ft_memcpy(text, "Right access to Mandelbrot's fractal !", 38);
	text[38] = '\0';
	mlx_string_put(data->mlx, data->win, 100, 50, color, text);
	ft_memset(text, 0, 39);
	ft_memcpy(text, "Type Enter to start visualisation", 33);
	text[34] = '\0';
	mlx_string_put(data->mlx, data->win, 100, 500, color, text);
	display_redirection(data);
}

void	display_julia(t_data *data)
{
	char	text[34];
	int		color;

	color = RED;
	ft_memset(text, 0, 34);
	ft_memcpy(text, "Right access to Julia's fractal !", 33);
	text[32] = '\0';
	mlx_string_put(data->mlx, data->win, 100, 50, color, text);
	ft_memset(text, 0, 34);
	ft_memcpy(text, "Type Enter to start visualisation", 33);
	mlx_string_put(data->mlx, data->win, 100, 500, color, text);
	display_redirection(data);
}

void	display_newton(t_data *data)
{
	char	text[35];
	int		color;

	color = RED;
	ft_memset(text, 0, 35);
	ft_memcpy(text, "Right access to Newton's fractal !", 34);
	text[34] = '\0';
	mlx_string_put(data->mlx, data->win, 100, 50, color, text);
	ft_memset(text, 0, 35);
	ft_memcpy(text, "Type Enter to start visualisation", 34);
	mlx_string_put(data->mlx, data->win, 100, 500, color, text);
	display_redirection(data);
}

void	display_exit_message(t_data *d)
{
	char	text[29];

	ft_memset(&text, 0, 29);
	ft_memcpy(&text, "PROGRAM RESTARTED AS DEFAULT", 29);
	mlx_string_put(d->mlx, d->win, d->s.wi / 4, d->s.hi / 2, RED, text);
	display_redirection(d);
}
