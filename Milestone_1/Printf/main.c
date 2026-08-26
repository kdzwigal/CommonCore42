/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:28:49 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/06 13:28:50 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a;
	char	*s = "string";
	char	c;
	int	pri;
	
	c = 'h';
	a = -123456789;
	printf("\n");
	printf("\n");

	pri = printf("printf === To jest \n pelne zdanie, w ktorym wstawiam char ->%c<-,\nkawalek stringa->%s<-, wartosc hex ->%X<-, wartosc male hex ->%x<-,\npointer _->%p<-, procent ->%%<-, unsigned ->%u<-, \nasd \n", c, s, a, a, s, a);
	printf("===============tyle zwraca printf ===>      %d\n", pri);
	printf("printf  %%c -> c  |%c|\n", c);
	printf("printf  %%s -> s  |%s|\n", s);
	printf("printf  %%p -> s  |%p|\n", s);
	printf("printf  %%p -> a  |%p|\n", &a);
	printf("printf  %%d -> a  |%d|\n", a);
	printf("printf  %%i -> a  |%i|\n", a);
	printf("printf  %%u -> a  |%u|\n", a);
	printf("printf  %%x -> a  |%x|\n", a);
	printf("printf  %%p -> a  |%p|\n", &a);
	printf("printf  %%X -> a  |%X|\n", a);
	printf("printf  %%%%       |%%|\n");
	printf("znak nowej linii -> \n<-");
	pri = printf("\n");
	printf("===============tyle zwraca printf na n ===>      %d\n", pri);
	printf("\n");
	printf("Hello, %s! The answer is %d, and pointer is %p.\n", "world", 42, &main);

	pri = ft_printf("ft_printf === To jest \n pelne zdanie, w ktorym wstawiam char ->%c<-,\nkawalek stringa->%s<-, wartosc hex ->%X<-, wartosc male hex ->%x<-,\npointer _->%p<-, procent ->%%<-, unsigned ->%u<-, \nasd \n", c, s, a, a, s, a);
	ft_printf("===============tyle zwraca ft_printf (3 wiecej bo ft_) ===>   %d\n", pri);
	ft_printf("ft_printf  %%c -> c  |%c|\n", c);
	ft_printf("ft_printf  %%s -> s  |%s|\n", s);
	ft_printf("ft_printf  %%p -> s  |%p|\n", s);
	ft_printf("ft_printf  %%p -> a  |%p|\n", &a);
	ft_printf("ft_printf  %%d -> a  |%d|\n", a);
	ft_printf("ft_printf  %%i -> a  |%i|\n", a);
	ft_printf("ft_printf  %%u -> a  |%u|\n", a);
	ft_printf("ft_printf  %%x -> a  |%x|\n", a);
	ft_printf("ft_printf  %%p -> a  |%p|\n", &a);
	ft_printf("ft_printf  %%X -> a  |%X|\n", a);
	ft_printf("ft_printf  %%%%       |%%|\n");
	ft_printf("znak nowej linii -> \n<-");
	ft_printf("Hello, %s! The answer is %d, and pointer is %p.\n", "world", 42, &main);
		
	pri = ft_printf("\n");
	ft_printf("===============tyle zwraca ft_printf na n ===>      %d\n", pri);

	return (0);
}
