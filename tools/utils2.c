/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:20:35 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 13:03:09 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "get_next_line.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*str;

	str = ptr;
	while (n-- != 0)
		*str++ = (unsigned char)c;
	return (ptr);
}

size_t	ft_isfloat(char *str, size_t len)
{
	int	i;
	int	minus;
	int	point;

	i = 0;
	minus = 0;
	point = 0;
	while (len > 0 && str[i])
	{
		if (str[i] == '.')
			point++;
		else if (str[i] == '-')
			minus++;
		else if (!ft_isdigit(str[i]))
			break ;
		if (minus > 1 || point > 1)
			break ;
		len--;
		i++;
	}
	if (len > 0)
		return (0);
	return (getlen(str));
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

double	ft_atof(const char *s)
{
	int		i;
	int		neg;
	double	frn;
	double	res;
	double	div;

	i = 0;
	neg = 1;
	res = 0;
	frn = 0;
	if (s[i++] == '-')
		neg = -1;
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - '0');
	if (s[i++] == '.')
	{
		div = 10;
		while (ft_isdigit(s[i]))
		{
			frn += (s[i++] - '0') / div;
			div *= 10;
		}
	}
	return (neg * (res + frn));
}
