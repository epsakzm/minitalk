/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:43:21 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/19 14:05:18 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	size_t	out;
	int		neg;

	i = 0;
	neg = 1;
	out = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out * neg);
}

void	ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	*ft_memset(void *b, int c, size_t len, int *length)
{
	unsigned int	*ret;

	ret = b;
	*length = 0;
	while (len--)
		*ret++ = (unsigned char)c;
	return ((void *)b);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
