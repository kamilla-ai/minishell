/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_related_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:31:26 by mrhelmy           #+#    #+#             */
/*   Updated: 2024/09/05 14:45:58 by krazikho         ###   ########.fr       */
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

char	*substr_after_char(char *str, char c)
{
	int		i;
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (NULL);
	i++;
	while (str[i + len])
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	len = 0;
	while (str[i])
		new_str[len++] = str[i++];
	new_str[len] = '\0';
	return (new_str);
}

char	*substr_before_char(char *str, char c)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

t_env	*create_env_nodes(char *variable_content, char *value_content)
{
	t_env	*list;

	list = malloc(sizeof(t_env));
	if (!list)
		return (NULL);
	list->variable = variable_content;
	list->value = value_content;
	list->next = NULL;
	return (list);
}

t_env	*storing_env(char **ev)
{
	t_env	*env;
	t_env	*tmp;
	t_env	*newnode;
	int		i;

	if (!ev || !ev[0])
		return (NULL);
	env = create_env_nodes(substr_before_char(ev[0], '='),
			substr_after_char(ev[0], '='));
	if (!env)
		return (NULL);
	newnode = NULL;
	tmp = env;
	i = 1;
	while (ev[i])
	{
		newnode = create_env_nodes(substr_before_char(ev[i], '='),
				substr_after_char(ev[i], '='));
		if (!newnode)
			return (free_env(env), NULL);
		tmp ->next = newnode;
		tmp = tmp->next;
		i++;
	}
	return (env);
}

static char *concat_var_value(const char *variable, const char *value) {
    size_t var_len = ft_strlen(variable);
    size_t val_len = ft_strlen(value);
    char *result = malloc(var_len + val_len + 2); // +2 for '=' and '\0'
    if (result == NULL) {
        perror("malloc");
        return NULL;
    }
    
    // Copy the variable name
    ft_strlcpy(result, variable, ft_strlen(result));
    // Append '='
    result[var_len] = '=';
    // Append the value
    ft_strlcpy(result + var_len + 1, value, ft_strlen(result));
    
    return result;
}

// Convert t_env linked list to array of strings for execve
char **convert_env(t_env *env) {
    int count = 0;
    t_env *temp = env;

    // Count the number of environment variables
    while (temp) {
        count++;
        temp = temp->next;
    }

    // Allocate memory for the array of strings
    char **env_array = malloc((count + 1) * sizeof(char *));
    if (env_array == NULL) {
        perror("malloc");
        return NULL;
    }

    // Populate the array
    temp = env;
    int i = 0;
    while (temp) {
        env_array[i] = concat_var_value(temp->variable, temp->value);
        if (env_array[i] == NULL) {
            // Free previously allocated memory in case of error
            int j = 0;
            while (j < i) {
                free(env_array[j]);
                j++;
            }
            free(env_array);
            return NULL;
        }
        i++;
        temp = temp->next;
    }

    env_array[count] = NULL; // Null-terminate the array
    return env_array;
}