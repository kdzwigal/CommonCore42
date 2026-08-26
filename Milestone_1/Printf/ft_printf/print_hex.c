/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:24:23 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/07 15:24:24 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number_base(unsigned long n, const char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base_len)
		count += print_number_base(n / base_len, base, base_len);
	write(1, &base[n % base_len], 1);
	return (count + 1);
}

int	print_hex_lower(va_list *args)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	return (print_number_base(num, "0123456789abcdef", 16));
}

int	print_hex_upper(va_list *args)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	return (print_number_base(num, "0123456789ABCDEF", 16));
}

int	print_unsigned(va_list *args)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	return (print_number_base(num, "0123456789", 10));
}

int	print_pointer(va_list *args)
{
	void			*ptr;
	unsigned long	address;
	int				length;

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	length = 2;
	length += print_number_base(address, "0123456789abcdef", 16);
	return (length);
}
