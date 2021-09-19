/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:45:16 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/19 14:06:59 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define RADIX 0x7f
#define SIG_MAX 0x8000
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
int			ft_is_printable(char c);
void		*ft_memset(void *b, int c, size_t len, int *length);
int			ft_strlen(char *str);

#endif