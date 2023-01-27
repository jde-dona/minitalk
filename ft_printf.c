/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-dona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:07 by jde-dona          #+#    #+#             */
/*   Updated: 2023/01/12 14:59:53 by jde-dona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr_baseu(unsigned int nbr)
{
	unsigned int		nb;
	int					count;	

	nb = nbr;
	if (nb >= 10)
	{
		count = ft_putnbr_baseu((nb / 10));
		count += ft_putnbr_baseu((nb % 10));
		return (count);
	}
	else
		return (ft_putchar((nb + '0')));
}

int	ft_putnbr(int nb)
{
	int	nbr;
	int	count;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
		count = 1;
	}
	else
	{
		nbr = (unsigned int)nb;
		count = 0;
	}
	count += ft_putnbr_baseu(nbr);
	return (count);
}

int	ft_core(char c, va_list args)
{
	int	count;

	if (c == 'i' || c == 'd')
		return (ft_putnbr((va_arg(args, int))));
	else if (c == '%')
		return (ft_putchar(c));
	else
	{
		count = ft_putchar('%');
		return (count + ft_putchar(c));
	}
}

int	perc_check(const char *str, va_list args)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_core(*str, args);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	count = perc_check(str, args);
	va_end(args);
	return (count);
}
