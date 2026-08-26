/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:58:05 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/16 10:58:07 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len > 0)
	{
		*(tmp++) = 0;
		len--;
	}
}
