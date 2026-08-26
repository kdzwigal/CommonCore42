/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:24:42 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/07 15:24:43 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_integer_number(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += print_integer_number(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	print_integer(va_list *args)
{
	int	num;
	int	length;

	num = va_arg(*args, int);
	length = print_integer_number(num);
	return (length);
}

int	print_string(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	print_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}
