/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:12:12 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/18 09:12:14 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && size > (((size_t) - 1) / nmemb))
		return (NULL);
	if (total_size == 0)
		arr = malloc(1);
	else
		arr = malloc(total_size);
	if (!arr)
		return (NULL);
	if (total_size == 0)
		ft_bzero(arr, 1);
	else
		ft_bzero(arr, total_size);
	return (arr);
}
