/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-dona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:29:18 by jde-dona          #+#    #+#             */
/*   Updated: 2023/01/12 15:02:53 by jde-dona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char av)
{
	int	i;

	if (av > 64)
	{
		i = 64;
		kill(pid, SIGUSR2);
	}
	else
		i = 0;
	while (i < (av + 1))
	{
		if (av != i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		while (av[2][i])
		{
			send_char(pid, av[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format mammelucco\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE_TO_SEND>\033[0m\n");
		return (1);
	}
	return (0);
}
