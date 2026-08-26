/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:55:48 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/14 16:20:29 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		endl_index;

	endl_index = gnl_strchr_n(stash);
	while (endl_index == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		stash = gnl_strjoin(stash, buffer, gnl_strlen(stash), bytes_read);
		if (stash == NULL)
			return (NULL);
		endl_index = gnl_strchr_n(stash);
	}
	return (stash);
}

char	*extract_and_update(char **stash, ssize_t endl_index)
{
	char	*ret;

	if (endl_index == -1)
	{
		ret = *stash;
		*stash = NULL;
		return (ret);
	}
	ret = gnl_substr(*stash, 0, endl_index + 1);
	if (!ret)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	*stash = gnl_newstash_free(*stash, endl_index + 1);
	return (ret);
}

char	*gnl_newstash_free(const char *src, size_t start)
{
	char			*dest;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = gnl_strlen(src);
	dest = malloc((len - start + 1) * sizeof(char));
	if (dest == NULL)
	{
		free((void *)src);
		return (NULL);
	}
	while (src[start + i] != '\0')
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	free((void *)src);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*ret;
	ssize_t		endl_index;

	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	endl_index = gnl_strchr_n(stash);
	ret = extract_and_update(&stash, endl_index);
	return (ret);
}
