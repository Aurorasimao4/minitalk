/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:12:45 by asimao            #+#    #+#             */
/*   Updated: 2024/08/02 11:18:51 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_bits(pid_t pid, char bit)
{
	if (bit & 0b10000000)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1000);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		send_bits(pid, c & 0b10000000);
		c <<= 1;
	}
}

void	send_mes(pid_t pid, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		send_char(pid, c[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int		valor;
	pid_t	pid;

	if (argc == 3)
	{
		valor = ft_atoi(argv[1]);
		pid = (pid_t)valor;
		send_mes(pid, argv[2]);
	}
	else
		write(1,"erro, insira: PID e mensagem\n", 29);
	return (0);
}
