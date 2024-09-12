/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:19:05 by asimao            #+#    #+#             */
/*   Updated: 2024/08/02 11:19:29 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler_signal(int signal)
{
	static int	index_bit;
	static char	c;

	if (signal == SIGUSR1)
		c |= 0b00000001;
	index_bit++;
	if (index_bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		index_bit = 0;
	}
	c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID: %d\n", getpid());
	while (1)
	{
		sa.sa_handler = handler_signal;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
