/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 08:46:58 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/06 08:47:00 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_stri(const char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_unknown(const char specifier)
{
	write(1, "%", 1);
	write(1, &specifier, 1);
	return (2);
}

static int	dispatch_str(const char specifier, va_list *args)
{
	if (specifier == 'c')
		return (print_char(args));
	else if (specifier == 's')
		return (print_string(args));
	else if (specifier == 'd' || specifier == 'i')
		return (print_integer(args));
	else if (specifier == 'u')
		return (print_unsigned(args));
	else if (specifier == 'x')
		return (print_hex_lower(args));
	else if (specifier == 'X')
		return (print_hex_upper(args));
	else if (specifier == 'p')
		return (print_pointer(args));
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (print_unknown(specifier));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total_printed;

	if (!str)
		return (-1);
	i = 0;
	total_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			i++;
			total_printed += dispatch_str(str[i], &args);
		}
		else
			total_printed += print_stri(str[i]);
		i++;
	}
	va_end(args);
	return (total_printed);
}
