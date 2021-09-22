/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:45:16 by hyeopark          #+#    #+#             */
/*   Updated: 2021/09/22 16:08:31 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
void		ft_mem_reset(void *b, size_t len);

#endif