/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:49:25 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/06 11:49:28 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	print_string(va_list *args);

int	print_char(va_list *args);

int	print_integer(va_list *args);

int	print_hex_lower(va_list *args);

int	print_hex_upper(va_list *args);

int	print_pointer(va_list *args);

int	print_unsigned(va_list *args);

#endif
