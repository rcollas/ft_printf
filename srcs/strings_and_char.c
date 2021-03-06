/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_and_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:24:54 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 19:51:29 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_str_len(t_spec *spec, char *str)
{
	if (spec->width > ft_strlen(str) && spec->zero)
		spec->put_zero = spec->width - ft_strlen(str);
	else if (spec->width > ft_strlen(str) && spec->dot && !spec->precision)
		spec->put_space = spec->width;
	else if (spec->width > ft_strlen(str) && !spec->precision)
		spec->put_space = spec->width - ft_strlen(str);
	else if (spec->dot && spec->width > spec->precision
		&& spec->precision <= ft_strlen(str))
		spec->put_space = spec->width - spec->precision;
	else if (spec->width > ft_strlen(str) && spec->precision > ft_strlen(str))
		spec->put_space = spec->width - ft_strlen(str);
}

void	ft_putstring(va_list str, t_spec *spec)
{
	char	*string;
	int		i;

	i = 0;
	string = va_arg(str, char *);
	if (!string)
		string = "(null)";
	get_str_len(spec, string);
	if (!spec->dash)
	{
		spec->count += ft_putnchar(' ', spec->put_space);
		spec->count += ft_putnchar('0', spec->put_zero);
	}
	if (spec->dot)
		while (string[i] && i < spec->precision)
			spec->count += write(1, &string[i++], 1);
	else
		while (string[i])
			spec->count += write(1, &string[i++], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}

int	get_char_len(t_spec *spec)
{
	int	len;

	len = 0;
	if (spec->width > 1 && spec->dot && !spec->precision)
		len = spec->width - 1;
	else if (spec->width > 1 && !spec->precision)
		len = spec->width - 1;
	else if (spec->dot && spec->width > spec->precision && spec->precision <= 1)
		len = spec->width - 1;
	else if (spec->width > 1 && spec->precision > 1)
		len = spec->width - 1;
	return (len);
}

void	ft_putchar(va_list c, t_spec *spec)
{
	char	to_print;
	int		len;

	to_print = va_arg(c, int);
	len = get_char_len(spec);
	if (!spec->dash)
		spec->count += ft_putnchar(' ', len);
	spec->count += write (1, &to_print, 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', len);
}
