#include "fractals.h"

void	merrors(int sig)
{
	if (sig == 1)
		ft_putstr("Mauvais nombre d'argument pegu\n");
	if (sig == 2)
		ft_putstr("zz\n");
	if (sig == -1)
		ft_putstr("Ceci n'est pas un nombre\n");
	if (sig == 8)
		ft_putstr("FUCK\n GOT IT OK ?!\n");
}

void	mrules(int sig)
{
	if (sig == 1)
	{
		ft_putstr("Salut, salut ! Avant de lancer l'application graphique ");
		ft_putstr("tu dois decider avec quelles regles tu veux executer le ");
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
}