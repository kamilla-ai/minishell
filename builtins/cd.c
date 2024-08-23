/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:00:29 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/23 14:32:53 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cd(char **args, t_env **envir){
    char *path;
    (void)envir;
    char cwd[1024];
    if(!args[1]){
        path=getenv("HOME");;
        if(!path){
            printf("Error reading $HOME.\n");
            return;
        }
    }else if(args[1][0]=='-'){
        if(args[1][1]=='\0')
            ;
        else if(args[1][1]=='L')
            ;
        else if(args[1][1]=='P')
            ;
        else{
            printf("-bash: cd: %c%c: invalid option\n", args[1][0], args[1][1]);
            printf("cd: usage: cd [-L|-P] [dir]\n");
            return;
        }
    }else{
        if(args[1][0]=='$'){
            path=getenv(&args[1][1]);
        }else{
            path=args[1];
        }
    }
    if(chdir(path)!=0){
        printf("cd: string not in pwd: %s\n", args[1]);
    }else{
        update_env(envir, "OLDPWD", "OLDPWD");
        update_env(envir, "PWD", "NEWPWD");
        update_env(envir, "PWD", getcwd(cwd, sizeof(cwd)));
    }
}
