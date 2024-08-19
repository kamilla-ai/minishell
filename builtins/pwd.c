/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:05 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/19 16:23:16 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// void echo(char *message){
//     printf("%s", message);
// }

void pwd(){
    char cwd[1024];
    printf("%s\n",getcwd(cwd, sizeof(cwd)));
}
