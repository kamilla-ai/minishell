/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:31:26 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/08/19 11:51:47 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *substr_after_char(char *str , char c)
{
	int i;
	int len;
	
	if (!str)
        return (NULL);
	i = 0;
	len = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (NULL);
	i++;
	while(str[i + len])
		len++;
	char *new_str = malloc(sizeof(char) * (len) + 1);
	if (!new_str)
		return (NULL);
	len = 0;
	while(str[i])
		new_str[len++] = str[i++];
	new_str[len] = '\0';
	return (new_str);
}

char *substr_before_char(char *str , char c)
{
	int i;

	if (!str)
        return (NULL);
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			break;
		i++;
	}
	char *new_str = malloc(sizeof(char) * i);
	if (!new_str)
		return (NULL);
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			break;
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

t_env *create_env_Nodes(char *variable_content, char *value_content)
{
	t_env *list;

	list = malloc(sizeof(list));
	if (!list)
		return (NULL);
	list->variable = variable_content;
	list->value = value_content;
	list->next = NULL;
	return (list);
}

t_env *storing_env(char **ev)
{
	t_env *env;
	t_env *tmp;
	t_env *newnode;
	int i;

	if (!ev || !ev[0])
        return NULL;
	env = create_env_Nodes(substr_before_char(ev[0], '='), substr_after_char(ev[0], '='));
	if (!env)
        return (NULL);
	newnode = NULL;
	tmp = env;
	i = 1;
	
	while(ev[i])
	{
		newnode = create_env_Nodes(substr_before_char(ev[i], '='), substr_after_char(ev[i], '='));
		if (!newnode)
			return (free_env(env), NULL);
		tmp ->next = newnode;
		tmp = tmp->next;
		i++;
	}
	// printlist(env);
	return (env);
}