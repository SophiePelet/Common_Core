/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:33:24 by sopelet           #+#    #+#             */
/*   Updated: 2025/12/30 15:42:06 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	check_stash(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	byte_read;
	char	*tmp_stash;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !check_stash(stash))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		tmp_stash = ft_strjoin_gnl(stash, buffer);
		free(stash);
		stash = tmp_stash;
	}
	free(buffer);
	return (stash);
}

static char	*fill_line(char *filled_stash)
{
	char	*line;
	size_t	stash_len;
	size_t	i;

	stash_len = 0;
	i = 0;
	if (filled_stash == NULL)
		return (NULL);
	if (filled_stash[0] == '\0')
		return (NULL);
	while (filled_stash[stash_len] != '\0' && filled_stash[stash_len] != '\n')
		stash_len++;
	if (filled_stash[stash_len] == '\n')
		stash_len += 1;
	line = ft_calloc((stash_len + 1), sizeof(char));
	if (!line)
		return (NULL);
	while (i < stash_len)
	{
		line[i] = filled_stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *filled_stash)
{
	size_t	i;
	char	*stash_remainder;

	i = 0;
	while (filled_stash[i] && filled_stash[i] != '\n')
		i++;
	if (filled_stash[i] == '\n')
	{
		i++;
		stash_remainder = ft_strdup_index(filled_stash, i);
	}
	else
		return (NULL);
	return (stash_remainder);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*filled_stash;
	char		*line;
	char		*new_stash;

	filled_stash = fill_stash(fd, stash);
	if (!filled_stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = fill_line(filled_stash);
	new_stash = clean_stash(filled_stash);
	stash = new_stash;
	free(filled_stash);
	return (line);
}

/* int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("nope"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("call : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
} */