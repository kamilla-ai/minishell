/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:00:02 by krazikho          #+#    #+#             */
/*   Updated: 2024/08/29 13:40:35 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *getcopyenv(char *str, t_env **envir){
    t_env *tmp;
		
	tmp = *envir;
    while (tmp != NULL) {
        if (ft_strcmp(tmp->variable, str) == true) {  // Check for equality explicitly
            return tmp->value;  // Return the value if found
        }
        tmp = tmp->next;  // Move to the next node
    }
    return NULL;
}

void update_env_for_cd(t_env **env, char *variable, char *value)
{
	t_env *tmp;
	t_env *new_node;
	
	tmp = *env;
	
	while(tmp != NULL)
	{
		if (num_strncmp(tmp->variable, variable) == 0)
        {
            tmp->value = ft_strdup(value);
            return;
        }
		tmp = tmp->next;
	}
	new_node = create_env_nodes(variable, value);
    if (new_node != NULL)
    {
        new_node->next = *env;
        *env = new_node;
    }
    else 
        printf("Error");
}
