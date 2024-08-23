/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:10:03 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/08/23 14:23:25 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int num_strncmp(char *s1, char* s2)
{
	int i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

void update_env(t_env **env, char *variable, char *value)
{
	t_env *tmp;
	t_env *new_node;
	
	tmp = *env;
	
	while(tmp != NULL)
	{
		if (num_strncmp(tmp->variable, variable) == 0)
        {
            // free(tmp->value);
            tmp->value = value;
            // free(variable);
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
        printf("Erorr");
}

void export_with_args(t_env **env, int ac, char **av)
{
	int i = 1;
	char *variable;
    char *value;
    
    while(i < ac)
    {
        variable = substr_before_char(av[i], '=');
        value = substr_after_char(av[i], '=');
   
        if (variable == NULL || *variable == '\0')
        {
            printf("invalid");
            free(variable);
            free(value);
        }
        else 
           	update_env(env, variable, value);
        i++;
    }
}
