/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:14:08 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/17 11:14:11 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	tmpc;
	unsigned char	*tmps;

	tmps = (unsigned char *) s;
	tmpc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (tmps[i] == tmpc)
			return ((void *)&tmps[i]);
		i++;
	}
	return (NULL);
}
