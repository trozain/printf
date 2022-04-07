/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:20:16 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:20:16 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	c;

	c = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		c += ft_treat_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	c += ft_putstrprec(d_i, ft_strlen(d_i));
	return (c);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.minus == 1)
		c += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		c += ft_treat_width(flags.width, 0, 0);
	}
	else
		c += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		c += ft_in_put_part_int(d_i, save_i, flags);
	return (c);
}

int	ft_treat_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		c;

	save_i = i;
	c = 0;
	if (flags.dot == 0 && i == 0)
	{
		c += ft_treat_width(flags.width, 0, 0);
		return (c);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		c++;
	}
	d_i = ft_itoa(i);
	c += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (c);
}
