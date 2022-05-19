/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_src1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:20:24 by smichoud          #+#    #+#             */
/*   Updated: 2022/05/19 14:26:44 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

int	ft_write_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_write_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_write_p(unsigned long n, int first_round)
{
	int	i;

	i = 0;
	if (first_round)
		i += write(1, "0x", 2);
	if (n >= 16)
	{
		i += ft_write_p(n / 16, 0);
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

int	ft_write_di(int n)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += ft_write_di(nb / 10);
		i += ft_write_di(nb % 10);
	}
	else
		i += ft_write_c(nb + '0');
	return (i);
}
