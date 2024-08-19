# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 14:53:08 by krazikho          #+#    #+#              #
#    Updated: 2024/08/19 15:34:47 by krazikho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline


NAME_SRCS = main.c utils.c execute_command.c execute_builtin.c builtins.c

NAME_OBJS = $(NAME_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(NAME_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(NAME_OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(NAME_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
