/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:43:46 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/23 00:31:41 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static char		c;
	static int		len;
	static int		bit;
	static char		buf[BUF_SIZE];

	if (len == BUF_SIZE)
	{
		ft_putstr(buf);
		ft_mem_reset(buf, BUF_SIZE, &len);
	}
	c = (c << 1) + signal - 30;
	if (++bit == 7)
	{
		bit = 0;
		if (c == 0)
		{
			ft_putstr(buf);
			ft_mem_reset(buf, BUF_SIZE, &len);
			return ;
		}
		buf[len++] = c;
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
