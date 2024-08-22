/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:58:22 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/21 21:24:00 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **ev){
    (void)ac;
    (void)av;
    char *command;
    t_env *envir;
    envir = storing_env(ev);
    while(1)
    {
        command = readline("minishell$ ");
        if (command == NULL) {
            break;
        }
        if (*command) {
            add_history(command);
            
            envir = execute_command(command, envir);
        }
        free(command);
    }
    free_env(envir);
    return 0;
}
