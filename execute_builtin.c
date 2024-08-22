/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:55:09 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/22 13:47:57 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_args(char **args) 
{
    int count;
    
    count = 0;
    while (args[count] != NULL)
        count++;
    return (count);
}

t_env *execute_builtin(char *command, t_env *envir, char **args){
	int count;

	(void)command;
	if (!args || !args[0]) 
        return (envir);
	count = count_args(args);
	if (ft_strcmp("echo", args[0])==true)
	{
		;
		// echo();
    }
    else if(ft_strcmp("cd", args[0])==true)
    {
		;
		// cd();
    }
    else if(ft_strcmp("pwd", args[0])==true)
    {
        pwd();
    }
    else if(ft_strcmp("export", args[0])==true)
    {
        if (args[1] != NULL)
			export_with_args(&envir, count, args);
		else 
            export_no_arg(envir);
    }
    else if(ft_strcmp("unset", args[0])==true)
    {
        if (args[1] != NULL)
           unset(&envir, count, args);
	}
    else if(ft_strcmp("env", args[0])==true){
        env(envir);
    }
    else if(ft_strcmp("exit", args[0])==true){
        ;
        // exit();
    }
    // free_arr(args);
    return (envir);
}
