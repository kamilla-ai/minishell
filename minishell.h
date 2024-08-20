/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:58:51 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/20 16:01:49 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>

// our environment struct
typedef struct env
{
	char *variable;
	char *value;
	struct env *next;
} t_env;

// Functions used to store the enironment in the struct

t_env   *create_env_Nodes(char *variable_content, char *value_content); // warning malloc used
t_env   *storing_env(char **ev); // warning createNodes used here which uses malloc
void    free_env(t_env *env);

// env command (printing the environment)

void    env(t_env *env);

// We might use them, globally
char    *substr_before_char(char *str , char c); // warning malloc is used
char    *substr_after_char(char *str , char c); // warning malloc is used

void execute_command(char *command, t_env *env);
int	ft_strcmp(char *s1, char *s2);
void execute_builtin(char *command, t_env *env);
void pwd();
#endif
