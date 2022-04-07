/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:47:57 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:47:57 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_part_int(char *str, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.dot >= 0)
	{
		c += ft_treat_width(flags.dot, ft_strlen(str), 0);
		c += ft_putstrprec(str, flags.dot);
	}
	else
	{
		c += ft_putstrprec(str, ft_strlen(str));
	}
	return (c);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	c;

	c = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		c += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		c += ft_treat_width(flags.width, flags.dot, 0);
	else
		c += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		c += ft_put_part_int(str, flags);
	return (c);
}
