/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:24:19 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:24:19 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_percent(t_flags flags)
{
	int	c;

	c = 0;
	if (flags.minus == 1)
		c += ft_putstrprec("%", 1);
	c += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		c += ft_putstrprec("%", 1);
	return (c);
}
