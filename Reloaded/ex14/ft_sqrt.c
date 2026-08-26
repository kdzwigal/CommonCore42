/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:03:41 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/15 11:03:44 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	j;

	j = -23;
	while (j <= 2500)
	{
		if (ft_sqrt(j) != 0)
		{
			printf("\nistnieje pierwiastek z %d", j);
			printf(", jest to: %d\n", ft_sqrt(j));
		}
		j++;
	}
}*/
