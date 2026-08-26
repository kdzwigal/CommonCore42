/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:33:47 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/14 17:01:00 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t	src_len;

	if (!str)
		return (0);
	src_len = 0;
	while (str[src_len] != '\0')
	{
		src_len++;
	}
	return (src_len);
}

char	*gnl_strjoin(char *s1, char *s2, ssize_t s1_len, ssize_t s2_len)
{
	ssize_t	i;
	char	*dest;

	i = 0;
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (start >= gnl_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (gnl_strlen(s) - start < len)
		len = gnl_strlen(s) - start;
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

ssize_t	gnl_strchr_n(char *s)
{
	ssize_t	i;
	char	end;

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
