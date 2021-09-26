/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:41:37 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/26 16:40:01 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	num_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	num_length(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*out;
	int			len;

	len = num_length(n);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	out[len--] = '\0';
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
	}
	if (n == 0)
		out[len] = '0';
	while (n != 0)
	{
		out[len] = '0' + num_abs(n % 10);
		n /= 10;
		len--;
	}
	return (out);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	tmp;

	if (n < 0)
	{
		ft_putchar('-');
		tmp = n % 10;
		tmp = -tmp;
		if (n <= -10)
		{
			n /= 10;
			n = -n;
			ft_putnbr(n);
		}
		ft_putchar(tmp + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 10)
		ft_putchar(n + '0');
}
