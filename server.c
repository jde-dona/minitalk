/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-dona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:29:49 by jde-dona          #+#    #+#             */
/*   Updated: 2023/01/12 15:07:57 by jde-dona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	static int	i;

	if (!i && signal == SIGUSR2)
	{
		i = 63;
		signal = SIGUSR1;
	}
	i++;
	if (signal == SIGUSR2)
	{
		i--;
		write(1, &i, 1);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (1);
	}
	ft_printf("\033[107m\033[34mProcess ID: %d\n\033[0m", pid);
	ft_printf("Waiting for a message...\n");
	while (ac == 1)
	{
		signal(SIGUSR2, sig_handler);
		signal(SIGUSR1, sig_handler);
		pause();
	}
	return (0);
}
