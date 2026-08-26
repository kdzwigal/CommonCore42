/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:20:15 by pwarda            #+#    #+#             */
/*   Updated: 2026/08/05 17:15:15 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_parser(char type, va_list content)
{
	if (type == 'c')
		return (ft_putchar(va_arg(content, int)));
	if (type == 's')
		return (ft_putstr(va_arg(content, char *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(content, int)));
	if (type == 'p')
		return (ft_putaddress(va_arg(content, void *)));
	if (type == 'u')
		return (ft_putbase(va_arg(content, unsigned int), "0123456789"));
	if (type == 'x')
		return (ft_putbase(va_arg(content, unsigned int), "0123456789abcdef"));
	if (type == 'X')
		return (ft_putbase(va_arg(content, unsigned int), "0123456789ABCDEF"));
	if (type == '%')
		return (ft_putchar('%'));
	write(BENCH_FD, "%", 1);
	write(BENCH_FD, &type, 1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	content;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(content, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_printf_parser(str[i + 1], content);
			i += 2;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(content);
	return (count);
}
