/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:43:46 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/20 02:40:09 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit(int signal)
{
	static char		c;
	static int		len;
	static int		bit_cnt;
	static char		s[1000];

	if (len == 1000)
	{
		ft_putstr(s);
		ft_mem_reset(s, 1000);
		len = 0;
	}
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

int main(void)
{
	pid_t	pid;
	pid = getpid();
	ft_putstr("server pid = ");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1);
	return (0);
}
