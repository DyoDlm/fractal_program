/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:20:46 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 16:18:50 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "get_next_line.h"

static void	check_arguments(t_data *data, int i)
{
	int	meow;

	meow = 0;
	if (data->rules[0] == '0' && i == 0)
		data->s.disolvant = 1;
	else if (data->rules && i == 0)
		data->s.disolvant = 30;
	if (data->rules && i == 1)
		data->s.julia_cx = ft_atof(data->rules);
	if (data->rules && i == 2)
		data->s.julia_cy = ft_atof(data->rules);
	if (data->rules && i == 3)
	{
		meow = ft_atoi(data->rules);
		if (meow <= 2160 && meow >= 200)
			data->s.wi = ft_atoi(data->rules);
	}
	if (data->rules && i == 4)
	{
		meow = ft_atoi(data->rules);
		if (meow <= 3540 && meow >= 200)
			data->s.hi = ft_atoi(data->rules);
	}
}

static int	check_rules(t_data *data, char *line, int *iteration)
{
	int		i;
	size_t	len;

	len = getlen(line);
	i = *iteration;
	if (len >= 32)
		return (merrors(1), 1);
	data->rules = ft_strdup(line);
	if (!data->rules)
		return (merrors(8), 0);
	check_arguments(data, i);
	free(data->rules);
	*iteration += 1;
	mrules(((i) + 4));
	if (i > 4)
		return (0);
	return (1);
}

static int	intro(t_data *data)
{
	int		i;
	int		state;
	char	*line;

	i = 0;
	state = 0;
	line = NULL;
	mrules(1);
	while (1)
	{
		if (i == 4)
			state = 1;
		line = get_next_line(0, state);
		if (line)
		{
			if (!check_rules(data, line, &i))
				return (mrules(2), free(line), i);
			if (ft_strlen(line) != 0)
				mrules(3);
			free(line);
		}
		if (i >= 5)
			break ;
	}
	return (mrules(2), i);
}

void	init_data(t_data *data, char state)
{
	if (state == '0')
	{
		data->mlx = NULL;
		data->win = NULL;
	}
	data->mlx2 = NULL;
	data->win2 = NULL;
	data->s.hi = 1080;
	data->s.wi = 1540;
	data->s.size = 0;
	data->s.mpos = 0;
	data->s.zoom = 1.0;
	data->s.mx = 0;
	data->s.my = 0;
	data->s.log_i = 1;
	data->s.screen_mode = 0;
	data->s.color = WHITE;
	data->s.julia_cx = -0.7;
	data->s.julia_cy = 0.27015;
	data->rules = NULL;
	data->kimg = NULL;
	init_julia(data);
	init_newton(data);
	init_mandelbrot(data);
	init_control_screen(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (merrors(7), EXIT_FAILURE);
	init_data(&data, '0');
	if (av[1] && !ft_strncmp(av[1], "intro", 5))
		intro(&data);
	else if (av[1] && !ft_strncmp(av[1], "skip", 4))
		ft_putstr("DOMMAGE ! T'AS RATE L'INTRO.. (snif)\n");
	else
		return (merrors(7), EXIT_FAILURE);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.win = mlx_new_window(data.mlx, data.s.hi, data.s.wi, "WAW !");
	if (!data.win)
		return (free_to_go(&data, '0'), EXIT_FAILURE);
	display_home(&data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
	if (!ft_strncmp(av[1], "skip", 4))
		return (merrors(11), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
