/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:22:15 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/19 14:22:16 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i == n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	src_len;

	src_len = 0;
	while (str[src_len] != '\0')
		src_len++;
	return (src_len);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src)) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if ((src[ft_strlen(src)]) == '\0')
		ft_strncpy(dest, src, ft_strlen(src));
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[100] = "To jest string do kopiowania.";
	char	*efekt;
	
	efekt = ft_strdup(str);
	printf("pointer = %s\n", efekt);
	free(efekt);
}*/
