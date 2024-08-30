# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 14:53:08 by krazikho          #+#    #+#              #
#    Updated: 2024/08/29 14:29:23 by krazikho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell #changed name of the program

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline


NAME_SRCS = main.c execute/execute_command.c execute/execute_builtin.c execute/modify_args.c\
			utils/string_functions.c utils/env_related_utils.c utils/free.c utils/cd_utils.c utils/echo_utils.c\
			./builtins/pwd.c ./builtins/env.c ./builtins/export_no_args.c ./builtins/echo.c\
			./builtins/export_with_args.c ./builtins/unset.c  ./builtins/cd.c

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

.PHONY: all clean fclean re #Do we need it ?
