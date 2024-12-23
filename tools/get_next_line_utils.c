/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:25:03 by aseite            #+#    #+#             */
/*   Updated: 2024/10/23 17:31:34 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == 0 || !s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	j;

	srclen = 0;
	j = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	destlen = 0;
	srclen = 0;
	i = 0;
	while (dst[destlen] && destlen < size)
		destlen++;
	while (src[srclen])
		srclen++;
	if (destlen >= size)
		return (size + srclen);
	while (src[i] && size - 1 > destlen + i)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s2)
		return (s1);
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
	{
		free_data(&s1);
		return (NULL);
	}
	if (s1)
		ft_strlcpy(result, s1, len1 + 1);
	else
		result[0] = '\0';
	ft_strlcat(result, s2, len1 + len2 + 1);
	free(s1);
	return (result);
}
