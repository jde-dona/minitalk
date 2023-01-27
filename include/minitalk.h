/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-dona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:39 by jde-dona          #+#    #+#             */
/*   Updated: 2023/01/12 14:29:02 by jde-dona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <sys/types.h>
# include <signal.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr_baseu(unsigned int nbr);
int	perc_check(const char *str, va_list args);
int	ft_core(char c, va_list args);

#endif
