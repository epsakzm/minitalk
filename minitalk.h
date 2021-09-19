/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:45:16 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/20 02:31:44 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define SIG_MAX 0x8000
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
void		ft_mem_reset(void *b, size_t len);

#endif