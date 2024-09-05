/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:01:48 by krazikho          #+#    #+#             */
/*   Updated: 2024/09/05 15:53:47 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void execute_external(char **args, t_env *env, char *path){
    pid_t pid;
    char **env_array = convert_env(env);
    pid = fork();
    if (pid == -1) {
        perror("fork");
        free(path);
        free_arr(env_array);
        // exit(EXIT_FAILURE);
    }
    else if (pid == 0) { 
        if (execve(path, args, env_array) == -1) {
            perror("execve");
            // exit(EXIT_FAILURE);
        }
    }
    else { 
        int status;
        if (wait(&status) == -1) {
            perror("wait");
        }
        free(path);
        free_arr(env_array);
    }
}