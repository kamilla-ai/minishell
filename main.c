/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:58:22 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/14 14:58:26 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void user_input(char *command){
    read(0, command, sizeof(command));
}

static void display_prompt(){
    printf("minishell$");
}

int main(){
    char command[128];
    while(1)
    {
        display_prompt();
        user_input(command);
        execute_command(command);
    }
    return 0;
}
