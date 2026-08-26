/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:41:17 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/16 10:41:20 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len > 0)
	{
		*(tmp++) = (unsigned char) c;
		len--;
	}
	return (s);
}
