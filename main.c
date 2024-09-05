/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:58:22 by krazikho          #+#    #+#             */
/*   Updated: 2024/09/05 12:07:17 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **ev){
    (void)ac;
    (void)av;
    char *command;
    t_env *envir;
    int last_exit_status;
	last_exit_status = 0; 
    envir = storing_env(ev);
    configure_terminal_behavior();
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    while(1)
    {
        command = readline("minishell$ ");
        if (command == NULL) {
            write(1, "exit\n", 5);
            break;
        }
        if (*command) {
            add_history(command);
            envir = execute_command(command, envir, &last_exit_status);
        }
        free(command);
    }
    free_env(envir);
    return (last_exit_status);
}
