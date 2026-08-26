/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:55:48 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/12 14:09:23 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

size_t	ft_strlen(const char *str)
{
	size_t	src_len;

	src_len = 0;
	while (str[src_len] != '\0')
	{
		//printf("___%c->", str[src_len]);
		src_len++;
	}
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t s2_len)
{
	ssize_t	i;
	ssize_t	s1_len;
	char	*dest;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	i = 0;
	//printf("___%zd->", s1_len);
	dest = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dest == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		dest[s1_len + i] = s2[i];
		i++;
	}
	dest[s1_len + i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (start >= ft_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_newstash_free(const char *src, size_t start)
{
	char			*dest;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(src);
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

ssize_t	ft_strchr_n(char *s)
{
	ssize_t		i;
	char			end;

	end = '\n';
	i = 0;
	if (!s)
		return (-1);
	while (s[i] != 0)
	{
		if (s[i] == end)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash = NULL;
	char		*ret = NULL;
	ssize_t		endl_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	endl_index = ft_strchr_n(stash);
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
		stash = ft_strjoin(stash, buffer, bytes_read);
		if (stash == NULL)
			return (NULL);
		endl_index = ft_strchr_n(stash);
	}
	if (stash == NULL || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (endl_index > -1)
	{
		ret = ft_substr(stash, 0, endl_index + 1);
		if (!ret)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash = ft_newstash_free(stash, endl_index + 1);
		return (ret);
	}
	else if (endl_index == -1)
	{
		ret = stash;
		stash = NULL;
		return (ret);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	fd;
	char		*print;
	int			i;

	if (argc == 1)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_puterr("Cannot read file.\n");
		else
		{
			i = 0;
			print = get_next_line(fd);
			while (print != NULL)
			{
				printf("%p\n", &print);
				printf("\npetla main %d \n", ++i);
				printf("%s\n", print);
				free(print);
				print = get_next_line(fd);
			}
			printf("%p\n", &print);
		}
	}
	return (0);
}
