/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:19:57 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:56:54 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

double	pw(double n, int degree)
{
	while (degree-- > 1)
		n *= n;
	return (n);
}

void	id3(double n1, char op, double n2, double *res)
{
	if (op == '-')
		res[0] = pw(n1, 2) - pw(n2, 2);
	if (op == '-')
		res[1] = -2 * n1 * n2;
	else
	{
		res[0] = pw(n1, 2) - pw(n2, 2);
		res[1] = 2 * n1 * n2;
	}
}

void	id2(double n1, char op, double n2, double *res)
{
	if (op == '-')
	{
		res[0] = pw(n1, 3) + 3 * pw(n2, 2) * n1;
		res[1] = -pw(n2, 3) + 3 * pw(n1, 2) * n2;
	}
	else
	{
		res[0] = pw(n1, 3) - 3 * pw(n2, 2) * n1;
		res[1] = -pw(n2, 3) + 3 * pw(n1, 2) * n2;
	}
}
/*
int	main()
{
	double n;
	double	tab[2];

	tab[0] = 0.0;
	tab[1] = 0.0;
	n = pw(3.0, 3);
	printf("P3, 3 : %lf\n", n);
	csec_id_degree(3.0, '+', 4.0, tab);
	printf("tab 0 : %lf\n", tab[0]);
	printf("tab 1 : %lf\n", tab[1]);
	return (1);
}*/
