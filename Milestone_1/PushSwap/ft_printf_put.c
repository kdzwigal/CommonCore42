/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:53:05 by pwarda            #+#    #+#             */
/*   Updated: 2026/08/05 19:46:44 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(BENCH_FD, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (write(BENCH_FD, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
		write(BENCH_FD, &str[i++], 1);
	return (i);
}

int	ft_putaddress(void *ptr)
{
	if (!ptr)
		return (write(BENCH_FD, "(nil)", 5));
	return (write(BENCH_FD, "0x", 2)
		+ ft_putbase((unsigned long)ptr, "0123456789abcdef"));
}

int	ft_putbase(unsigned long n, const char *base)
{
	unsigned long	len;
	int				result;

	len = 0;
	while (base[len])
		len++;
	result = 0;
	if (n >= len)
		result += ft_putbase(n / len, base);
	result += write(BENCH_FD, &base[n % len], 1);
	return (result);
}

int	ft_putnbr(int n)
{
	if (n < 0)
		return (write(BENCH_FD, "-", 1)
			+ ft_putbase((unsigned long)(-(long)n), "0123456789"));
	return (ft_putbase((unsigned long)n, "0123456789"));
}
