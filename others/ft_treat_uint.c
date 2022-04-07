/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:26:08 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:26:08 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_uint(char *unsi_int, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.dot >= 0)
		c += ft_treat_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	c += ft_putstrprec(unsi_int, ft_strlen(unsi_int));
	return (c);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.minus == 1)
		c += ft_in_put_part_uint(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		c += ft_treat_width(flags.width, 0, 0);
	}
	else
		c += ft_treat_width(flags.width, ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		c += ft_in_put_part_uint(unsi_int, flags);
	return (c);
}

int	ft_treat_uint(unsigned int unsi, t_flags flags)
{
	char	*u;
	int		c;

	c = 0;
	unsi = (unsigned int)(4294967295 + 1 + unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		c += ft_treat_width(flags.width, 0, 0);
		return (c);
	}
	u = ft_u_itoa(unsi);
	c += ft_put_part_uint(u, flags);
	free(u);
	return (c);
}
