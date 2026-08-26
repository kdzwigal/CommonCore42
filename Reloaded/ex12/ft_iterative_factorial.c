/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:08:59 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/18 15:09:02 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = nb;
	if (n < 0 || n > 12)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		nb--;
		n *= nb;
		if (n < 0 || n > 2147483647)
			return (0);
	}
	return (n);
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = -2;
	while (n <= 180)
	{
		printf("\n%d", n);
		printf("! = %d\n", ft_iterative_factorial(n));
		n++;
	}
	return (0);
}*/
