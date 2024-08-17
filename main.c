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

int main(){
    char *command;
    while(1)
    {
        command = readline("minishell$ ");
        // if (command == NULL) {
        //     break;
        // }
        // if (*command) {
        //     add_history(command);
        //     execute_command(command);
        // }
        
        free(command);
    }
    return 0;
}
