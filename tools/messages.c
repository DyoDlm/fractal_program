/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:20:18 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:59:02 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	merrors(int sig)
{
	if (sig == 1)
		ft_putstr("Evite d'ecrire un roman stp...\n");
	if (sig == 2)
		ft_putstr("zz\n");
	if (sig == -1)
		ft_putstr("Ceci n'est pas un nombre\n");
	if (sig == 8)
		ft_putstr("FUCK\n GOT IT OK ?!\n");
	if (sig == 7)
		ft_putstr("Bad number of arguments\nType ./fractol skip if"
			"you want to skip the introduction\n"
			"else type ./fractol intro\n");
	if (sig == 11)
		ft_putstr("Retry with the intro next time ;)\n");
}

void	mrules(int sig)
{
	if (sig == 1)
	{
		ft_putstr("Salut, salut ! Avant de lancer l'application"
			" graphique ");
		ft_putstr("tu dois decider avec quelles regles "
			"tu veux executer le ");
		ft_putstr("programme. \n\nVoici les options :\n\n");
		ft_putstr("MODE COULEUR :\n1 : OUI	2 : NON\n");
	}
	if (sig == 5)
		ft_putstr("PARAMETRES POUR JULIA (C):\n");
	if (sig == 4)
		ft_putstr("PARAMETRES POUR JULIA (Z):\n");
	if (sig == 3)
		ft_putstr("Reponse enregistree.\n\n");
	if (sig == 2)
		ft_putstr("Merci pour ta patience !\n");
	if (sig == 6)
		ft_putstr("Choose windows hight (max 2160):\n");
	if (sig == 7)
		ft_putstr("Choose windows widht (max 3540):\n");
}
