/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:10:44 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:10:44 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstrprec(char *str, int prec)
{
	int	c;

	c = 0;
	while (str[c] && c < prec)
		ft_putchar(str[c++]);
	return (c);
}
