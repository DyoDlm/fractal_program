/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_controler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:19:00 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:35:35 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "get_next_line.h"

void	free_info(t_data *cs)
{	
	int	i;

	i = 0;
	while (i < 17)
	{
		if (cs->cs.info.content[i])
			free(cs->cs.info.content[i]);
		i++;
	}
	if (cs->cs.info.content)
		free(cs->cs.info.content);
}

static int	alloc_info(t_data *cs)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		cs->cs.info.content[i] = malloc(32);
		if (!cs->cs.info.content[i])
			return (free_info(cs), 0);
		i++;
	}
	return (1);
}

static void	complete_conversion(t_data *cs)
{
	char	*tmp;

	tmp = ft_itoa(cs->f.j.l);
	cs->cs.info.content[7] = ft_strjoin(cs->cs.info.content[7], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.j.e);
	cs->cs.info.content[8] = ft_strjoin(cs->cs.info.content[8], tmp);
	free(tmp);
	tmp = ft_dtoa(cs->s.julia_cx, 5);
	cs->cs.info.content[9] = ft_strjoin(cs->cs.info.content[9], tmp);
	free(tmp);
	tmp = ft_dtoa(cs->s.julia_cy, 5);
	cs->cs.info.content[10] = ft_strjoin(cs->cs.info.content[10], tmp);
	free(tmp);
	tmp = ft_dtoa(cs->s.mx, 5);
	cs->cs.info.content[11] = ft_strjoin(cs->cs.info.content[11], tmp);
	free(tmp);
	tmp = ft_dtoa(cs->s.my, 5);
	cs->cs.info.content[12] = ft_strjoin(cs->cs.info.content[12], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.m.mi);
	cs->cs.info.content[14] = ft_strjoin(cs->cs.info.content[14], tmp);
	free(tmp);
}

int	convert_info(t_data *cs)
{
	char	*tmp;

	tmp = ft_dtoa(cs->s.zoom, 15);
	cs->cs.info.content[0] = ft_strjoin(cs->cs.info.content[0], tmp);
	free(tmp);
	tmp = ft_itoa(cs->s.screen_mode);
	cs->cs.info.content[1] = ft_strjoin(cs->cs.info.content[1], tmp);
	free(tmp);
	tmp = ft_dtoa(cs->s.color, 4);
	cs->cs.info.content[2] = ft_strjoin(cs->cs.info.content[2], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.m.b);
	cs->cs.info.content[3] = ft_strjoin(cs->cs.info.content[3], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.m.l);
	cs->cs.info.content[4] = ft_strjoin(cs->cs.info.content[4], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.m.e);
	cs->cs.info.content[5] = ft_strjoin(cs->cs.info.content[5], tmp);
	free(tmp);
	tmp = ft_itoa(cs->f.j.b);
	cs->cs.info.content[6] = ft_strjoin(cs->cs.info.content[6], tmp);
	free(tmp);
	complete_conversion(cs);
	return (1);
}

int	clear_info(t_data *cs)
{
	int	i;

	i = 0;
	if (!alloc_info(cs))
		return (0);
	while (i < 17 && cs->cs.info.content != NULL)
		ft_memset(cs->cs.info.content[i++], 0, BUF);
	return (1);
}
