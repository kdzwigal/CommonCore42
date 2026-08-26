/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:48:26 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/17 10:48:28 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			tmpc;

	tmpc = (char) c;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i > 0)
	{
		if (s[i] == tmpc)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == tmpc)
		return ((char *) &s[i]);
	return (NULL);
}
