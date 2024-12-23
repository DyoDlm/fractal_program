/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:19:49 by aseite            #+#    #+#             */
/*   Updated: 2024/12/19 22:19:51 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
/*
static int 	glf(double n)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0 && n != 1)
	{
		while (n > 1)
		{
			n /= 10;
			len++;
		}
		while (n < 1)
		{
			n += 0.000000000000001;
			i++;
		}
	}
	if (n == 1)
		return ();
	return ();
}*/

static int	gli(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

void	helper(int nb, char *str, int *index)
{
	if (nb >= 10)
		helper(nb / 10, str, index);
	str[(*index)++] = (nb % 10) + '0';
	str[*index] = '\0';
}

char	*ft_itoa(int n)
{
	char	*c;
	int		index;

	index = 0;
	c = (char *)malloc(gli(n) * sizeof(char));
	if (!c)
		return (NULL);
	if (n == -2147483648)
	{
		c[0] = '-';
		c[1] = '2';
		n += 2000000000;
		n = -n;
		index += 2;
	}
	else if (n < 0)
	{
		c[index++] = '-';
		n = -n;
	}
	helper(n, c, &index);
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	int	n = 0.1234;

	printf("%s \n", ft_btoa(n));
	return (0);
}*/
