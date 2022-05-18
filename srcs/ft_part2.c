/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:54:06 by smichoud          #+#    #+#             */
/*   Updated: 2022/05/16 18:58:50 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

int	ft_write_u(unsigned int n)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	nb = n;
	if (nb >= 10)
	{
		i += ft_write_u(nb / 10);
		i += ft_write_u(nb % 10);
	}
	else
		i += ft_write_c(nb + '0');
	return (i);
}

int	ft_write_x(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_write_x(n / 16);
		if (n % 16 < 10)
			i += ft_write_c((n % 16) + '0');
		else if (n % 16 >= 10)
			i += ft_write_c((n % 16) + 87);
	}
	else
	{
		if (n % 16 < 10)
			i += ft_write_c((n % 16) + '0');
		else if (n % 16 >= 10)
			i += ft_write_c((n % 16) + 87);
	}
	return (i);
}

int	ft_write_xx(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_write_xx(n / 16);
		if (n % 16 < 10)
			i += ft_write_c((n % 16) + '0');
		else if (n % 16 >= 10)
			i += ft_write_c((n % 16) + 55);
	}
	else
	{
		if (n % 16 < 10)
			i += ft_write_c((n % 16) + '0');
		else if (n % 16 >= 10)
			i += ft_write_c((n % 16) + 55);
	}
	return (i);
}
