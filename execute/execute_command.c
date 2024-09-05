/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:27:04 by krazikho          #+#    #+#             */
/*   Updated: 2024/09/05 15:55:59 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool is_builtin(char *command){
    if(ft_strcmp("echo", command)==true||ft_strcmp("cd", command)==true || ft_strcmp("pwd", command)==true) {
        return true;
    }else if(ft_strcmp("export", command)==true || ft_strcmp("unset", command)==true || ft_strcmp("env", command)==true){
        return true;
    }else if(ft_strcmp("exit", command)==true){
        return true;
    }else{
        return false;
    }
}

t_env *execute_command(char *command, t_env *envir, int *last_exit_status)
{
    char **args;
    char *path;
    args = ft_split(command, ' '); // just for testing later we can parse better (temporary)
    modify_args(args, envir);
    if (!args || !args[0])
        return envir;
    if (is_builtin(args[0])==true)
    {
        envir = execute_builtin(envir , args, last_exit_status);
	}
    else{
        path=find_executable(args[0], envir);
        if(path==NULL){
            printf("bash:command not found: %s\n", args[0]); // modifying this based on the bash syntax
            *last_exit_status = 127;
        }else{
            execute_external(args, envir, path);
            *last_exit_status = 0; 
        }
    }
    free_arr(args);
    return (envir);
}
