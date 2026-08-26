/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 10:46:32 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/08 11:19:04 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <math.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 7;
	b = 2;
	div = 0;
	mod = 0;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("div = %d\n", div);
	printf("mod = %d\n", mod);
	ft_div_mod(a, b, &div, &mod);
	printf("after ft_div_mod\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("div = %d\n", div);
	printf("mod = %d\n", mod);
}
*/
