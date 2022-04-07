/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:16:13 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:16:13 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_char(char c, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	c = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (c + 1);
}
