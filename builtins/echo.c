/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:03:09 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/29 13:43:56 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo(char **command, t_env *env){
    (void)env;
    bool n_flag;
    int i;
    int j;

    n_flag=false;
    i=1;
    while(command[i] && command[i][0]=='-' && is_only_n(command[i]+1)){
            n_flag=true;
            i++;
    }
    while(command[i]){
        j=0;
        while(command[i][j]){
            if(command[i][j]!='\\')
                printf("%c", command[i][j]);
            j++;
        }
        if(command[i+1])
            printf(" ");
        i++;
    }
    if(n_flag==false){
        printf("\n");
    }
}