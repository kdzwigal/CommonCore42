/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:17:05 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/16 12:17:09 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			tmpc;

	tmpc = (char) c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == tmpc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == tmpc)
		return ((char *) &s[i]);
	return (NULL);
}
