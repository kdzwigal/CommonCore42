/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:10:01 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/18 15:10:03 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = -2;
	while (n <= 25)
	{
		printf("\n%d", n);
		printf("! = %d\n", ft_recursive_factorial(n));
		n++;
	}
	return (0);
}*/
