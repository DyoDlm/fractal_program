/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_da_people.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:19:19 by aseite            #+#    #+#             */
/*   Updated: 2024/12/19 22:19:27 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	free_fractals_and_shit(t_data *data)
{
	if (data->f.j.img)
		mlx_destroy_image(data->mlx, data->f.j.img);
	if (data->f.m.img)
		mlx_destroy_image(data->mlx, data->f.m.img);
	if (data->f.n.img)
		mlx_destroy_image(data->mlx, data->f.n.img);
	if (data->cs.img)
		mlx_destroy_image(data->mlx2, data->win2);
	if (data->kimg)
		mlx_destroy_image(data->mlx, data->win);
}

void	free_lines(t_data *data)
{
	if (data->rules)
	{
		free(data->rules);
		data->rules = NULL;
	}
}

void	free_to_go(t_data *data, char state)
{
	free_fractals_and_shit(data);
	if (data->win && state == '0')
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx && state == '0')
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->cs.state == 1 && data->win2)
		mlx_destroy_window(data->mlx2, data->win2);
	if (data->cs.state == 1 && data->mlx2)
	{
		mlx_destroy_display(data->mlx2);
		free(data->mlx2);
	}
	data->f.j.a = NULL;
	data->f.n.a = NULL;
	data->f.m.a = NULL;
	data->cs.a = NULL;
}

void	replace_image(void **img, void *mlx, int wi, int hi)
{
	if (*img)
		mlx_destroy_image(mlx, *img);
	*img = mlx_new_image(mlx, wi, hi);
}
