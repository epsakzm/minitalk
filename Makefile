# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 13:52:42 by hyeopark          #+#    #+#              #
#    Updated: 2021/09/26 16:36:12 by hyeopark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Werror -Wall -Wextra

SERVER		= server
SERVER_SRCS	= server.o ft_utils.o

CLIENT		= client
CLIENT_SRCS	= client.o ft_utils.o

all: $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_SRCS)
	$(CC) $(CLIENT_SRCS) -o $(CLIENT)

$(SERVER): $(SERVER_SRCS)
	$(CC) $(SERVER_SRCS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(SERVER_SRCS) $(CLIENT_SRCS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
