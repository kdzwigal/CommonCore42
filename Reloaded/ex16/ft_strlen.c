/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:49:19 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/14 12:49:23 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	src_len;

	src_len = 0;
	while (str[src_len] != '\0')
		src_len++;
	return (src_len);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "123456789";
	printf("tyle: %d", ft_strlen(str));
}*/
