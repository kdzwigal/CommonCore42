/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:44:28 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/08 10:44:54 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 2;
	b = 4;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	ft_swap(&a, &b);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
}
*/
