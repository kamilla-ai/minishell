/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:17:37 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/09/05 14:08:47 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// our freeing functions
#include "../minishell.h"

void free_env(t_env *env)
{
	t_env *tmp;
	
	tmp = env;
	while (tmp != NULL)
	{
		tmp = env->next;
		free(env->variable);
		free(env->value);
		free(env);
		env = tmp;
	}
}

void free_env_node(t_env *node)
{
    if (node)
    {
        free(node->variable);
        free(node->value);
        free(node);
    }
}

void ft_free_split(char **split) {
    if (split == NULL) {
        return; // Nothing to free if the array is NULL
    }

    char **temp = split;
    while (*temp) {
        free(*temp); // Free each string
        temp++;
    }
    free(split); // Free the array of strings itself
}