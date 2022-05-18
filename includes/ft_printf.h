/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:28:46 by smichoud          #+#    #+#             */
/*   Updated: 2022/05/16 18:59:10 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_write_c(int c);
int	ft_write_s(char *str);
int	ft_write_p(unsigned long n, int first_round);
int	ft_write_di(int n);
int	ft_write_u(unsigned int n);
int	ft_write_x(unsigned int n);
int	ft_write_xx(unsigned int n);

#endif
