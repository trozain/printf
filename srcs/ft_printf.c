/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:19:11 by smichoud          #+#    #+#             */
/*   Updated: 2022/05/16 19:22:24 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

static int	ft_flag(const char format, va_list ap)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ft_write_c(va_arg(ap, int));
	else if (format == 's')
		i = ft_write_s(va_arg(ap, char *));
	else if (format == 'p')
		i = ft_write_p(va_arg(ap, unsigned long), 1);
	else if (format == 'd' || format == 'i')
		i = ft_write_di(va_arg(ap, int));
	else if (format == 'u')
		i = ft_write_u(va_arg(ap, unsigned int));
	else if (format == 'x')
		i = ft_write_x(va_arg(ap, unsigned int));
	else if (format == 'X')
		i = ft_write_xx(va_arg(ap, unsigned int));
	else if (format == '%')
		i = write(1, "%", 1);
	else
		i = write(1, &format, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			ret += write(1, &format[i], 1);
		else if (format[i] == '%')
			ret += ft_flag(format[++i], ap);
		i++;
	}
	va_end(ap);
	return (ret);
}
