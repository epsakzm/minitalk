/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:42:25 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/22 16:08:46 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send_bit(pid_t pid, char c)
{
	int		ret;

	if (c == 0)
		ret = kill(pid, SIGUSR1);
	else
		ret = kill(pid, SIGUSR2);
	usleep(200);
	return (ret + 1);
}

int		send_char(pid_t pid, char c)
{
	int		radix;
	
	radix = 6;
	while (radix >= 0)
		if (!send_bit(pid, c & (1 << radix--)))
			return (0);
	return (1);
}

int		send_message(pid_t pid, char *msg)
{
	while (*msg >= 32 && *msg <= 126)
		if (!send_char(pid, *msg++))
			return (0);
	return (send_char(pid, 0));
}

int		main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr("Argument(s) input error");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!send_message(pid, argv[2]))
	{
		ft_putstr("pid input error");
		return (1);
	}
	return (0);
}
