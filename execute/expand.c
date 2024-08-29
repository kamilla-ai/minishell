/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:04:39 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/29 13:41:03 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

char *double_quotes(char *arg, t_env *envir){
    int i;
    int len;
    char *res;
    (void)envir;
    i=0;
    len=ft_strlen(arg);
    res=malloc(sizeof(char)*(len-1));
    while(i<len-2){
        res[i]=arg[i+1];
        i++;
    }
    res[i]='\0';
    return res;
}

char *single_quotes(char *arg){
    int i;
    int len;
    char *res;
    i=0;
    len=ft_strlen(arg);
    res=malloc(sizeof(char)*(len-1));
    while(i<len-2){
        res[i]=arg[i+1];
        i++;
    }
    res[i]='\0';
    return res;
}

void change(char **args, t_env *envir){
    int i;
    i=0;
    (void)envir;
    while(args[i]){
        if(args[i][1] && args[i][0]=='$'){     
            if(getcopyenv(args[i]+1, &envir)){
                args[i]=getcopyenv(args[i]+1, &envir);
            }else{
                ft_strlcpy(args[i], "\0" , 1);
            } 
        }else if(args[i][0]=='\'' && args[i][ft_strlen(args[i])-1]=='\''){
            ft_strlcpy(args[i],single_quotes(args[i]), (ft_strlen(args[i])-1));
        }else if(args[i][0]=='"' && args[i][ft_strlen(args[i])-1]=='"'){
            ft_strlcpy(args[i],double_quotes(args[i], envir), (ft_strlen(args[i])-1));
        // }else{
        //     ft_strlcpy(args[i], skip_backslash(args[i], countbackslashandremove(args[i])));
        }
        i++;
    }
    // return envir;
}
