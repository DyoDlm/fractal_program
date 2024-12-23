/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:19:33 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:53:07 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "get_next_line.h"

static int	count_digits(int n)
{
	int	count;

	if (n == 0)
		count = 1;
	else
		count = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*minitoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	if (n < 0)
		len = count_digits(n) + 1;
	else
		len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	neg = (n < 0);
	if (neg)
		n = -n;
	while (len > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static char	*miniftoa(double fraction, int precision)
{
	int		i;
	int		digit;
	char	*str;

	i = 0;
	digit = 0;
	str = malloc(precision + 2);
	if (!str)
		return (NULL);
	str[0] = '.';
	while (i < precision)
	{
		fraction *= 10;
		digit = (int)fraction;
		str[i + 1] = digit + '0';
		fraction -= digit;
		i++;
	}
	str[precision + 1] = '\0';
	return (str);
}

char	*ft_dtoa(double value, int precision)
{
	int		ipart;
	double	fpart;
	char	*istr;
	char	*fstr;
	char	*result;

	if (precision < 0)
		precision = 0;
	ipart = (int)value;
	fpart = fabs(value - ipart);
	istr = minitoa(ipart);
	if (!istr)
		return (NULL);
	fstr = miniftoa(fpart, precision);
	if (!fstr)
		return (free(istr), NULL);
	result = ft_strjoin(istr, fstr);
	if (fstr)
		free(fstr);
	return (result);
}
