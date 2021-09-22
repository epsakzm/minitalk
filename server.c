/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:43:46 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/22 16:37:18 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static char		c;
	static int		len;
	static int		bit_cnt;
	static char		s[1000];

	c = (c << 1) + signal - 30;
	if (++bit_cnt == 7)
	{
		bit_cnt = 0;
		if (c == 0)
		{
			ft_putstr(s);
			ft_mem_reset(s, 1000);
			len = 0;
			c = 0;
			return ;
		}
		s[len++] = c;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("server pid = ");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		;
	return (0);
}
