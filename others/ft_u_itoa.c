/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:29:45 by trozain           #+#    #+#             */
/*   Updated: 2022/04/06 14:29:45 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_estim(long n)
{
	size_t	e;
	int		i;

	e = 0;
	i = 0;
	if (n < 0)
	{
		e++;
		i++;
		n = -n;
	}
	while (n >= 1)
	{
		e++;
		n /= 10;
	}
	return (e);
}

static char	*ft_gen(char *rtn, long nbr, int len, int i)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (i == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		i;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	i = 0;
	if (!(rtn == ft_gen(rtn, nbr, len, i)))
		return (0);
	return (rtn);
}
