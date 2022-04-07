/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:25:02 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:25:02 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int	c;

	c = 0;
	c += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		c += ft_treat_width(flags.dot, ft_strlen(pointer), 1);
		c += ft_putstrprec(pointer, flags.dot);
	}
	else
		c += ft_putstrprec(pointer, ft_strlen(pointer));
	return (c);
}

int	ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		c;

	c = 0;
	if (ull == 0 && flags.dot == 0)
	{
		c += ft_putstrprec("0x", 2);
		return (c += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		c += ft_in_put_part_pointer(pointer, flags);
	c += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		c += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (c);
}
