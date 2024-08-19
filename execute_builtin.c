/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:55:09 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/19 15:01:12 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void execute_builtin(char *command){
    if(ft_strcmp("echo", command)==true){
        ;
        // echo();
    }else if(ft_strcmp("cd", command)==true){
        ;
        // cd();
    }else if(ft_strcmp("pwd", command)==true){
        ;
        // pwd();
    }else if(ft_strcmp("export", command)==true){
        ;
        // export();
    }else if(ft_strcmp("unset", command)==true){
        ;
        // unset();
    }else if(ft_strcmp("env", command)==true){
        ;
        // env();
    }else if(ft_strcmp("exit", command)==true){
        ;
        // exit();
    }
}