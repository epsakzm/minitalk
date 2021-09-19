/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:43:46 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/19 13:52:32 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit(int signal)
{
	static char		temp;
	static int		length;
	static int		bit_cnt;
	static char		s[1000];

	if (length == 1000)
	{
		ft_putstr(s);
		ft_memset(s, '\0', 1000, &length);
	}
	temp = (temp << 1) + signal - 30;
	if (++bit_cnt == 7)
	{
		bit_cnt = 0;
		if (temp == 127)
		{
			ft_putstr(s);
			ft_memset(s, '\0', 1000, &length);
			temp = 0;
			return ;
		}
		s[length++] = temp;
		temp = 0;
	}
}

int main(void)
{
	pid_t	pid;
	pid = getpid();
	ft_putstr("server pid = ");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	while (1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
	}
	return (0);
}