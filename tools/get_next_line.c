/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:53:46 by aseite            #+#    #+#             */
/*   Updated: 2024/12/20 12:53:47 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	free_data(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

static char	*id_next(char **stack, char *next_line, int state)
{
	char	*line;
	char	*oflow;
	size_t	len;

	len = next_line - *stack + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stack, len + 1);
	oflow = malloc(ft_strlen(next_line + 1) + 1);
	if (!oflow)
		return (free(line), NULL);
	ft_strlcpy(oflow, next_line + 1, ft_strlen(next_line + 1) + 1);
	free_data(stack);
	*stack = oflow;
	if (state == 1)
		free(*stack);
	return (line);
}

static char	*extract_line(char **stack, int state)
{
	char	*next_line;
	char	*line;

	next_line = ft_strchr(*stack, '\n');
	line = NULL;
	if (next_line)
		return (id_next(stack, next_line, state));
	else
	{
		line = *stack;
		*stack = NULL;
	}
	return (line);
}

static int	update_stack(int fd, char **stack, char *buffer)
{
	int	bcount;

	while (!ft_strchr(*stack, '\n'))
	{
		bcount = read(fd, buffer, BUFFER_SIZE);
		if (bcount < 0)
			return (-1);
		if (bcount == 0)
			break ;
		buffer[bcount] = '\0';
		*stack = ft_strjoin(*stack, buffer);
		if (!*stack)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd, int state)
{
	static char	*stack = NULL;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	if (update_stack(fd, &stack, buffer) < 0)
		return (free_data(&stack), free(buffer), NULL);
	if (!stack || *stack == '\0')
		return (free_data(&stack), free(buffer), NULL);
	line = extract_line(&stack, state);
	free(buffer);
	return (line);
}
