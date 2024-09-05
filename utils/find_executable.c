/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:26 by krazikho          #+#    #+#             */
/*   Updated: 2024/09/05 15:54:40 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *build_full_path(const char *dir, const char *cmd) {
    // Allocate space for the full path: directory + '/' + command + '\0'
    size_t dir_len = strlen(dir);
    size_t cmd_len = strlen(cmd);
    char *full_path = malloc(dir_len + cmd_len + 2); // +2 for '/' and '\0'
    if (full_path == NULL) {
        perror("malloc");
        return NULL;
    }

    // Copy directory to full_path
    strcpy(full_path, dir);
    // Append '/'
    full_path[dir_len] = '/';
    // Append command
    strcpy(full_path + dir_len + 1, cmd);

    return full_path;
}

char *find_executable(char *cmd, t_env *envir){
    char **path_env;
    char *finalpath;
    int i;

    if (getcopyenv("PATH", &envir) == NULL) {
        return NULL;
    }
    path_env = ft_split(getcopyenv("PATH", &envir), ':');
    if (path_env == NULL) {
        return NULL;
    }
    i=0;
    while(path_env[i]){
        finalpath=build_full_path(path_env[i], cmd);
        if(!finalpath){
            perror("malloc");
            ft_free_split(path_env); 
            return NULL;
        }
        if (access(finalpath, X_OK) == 0) { // Check if file is executable
            ft_free_split(path_env); // Free memory used for splitting PATH
            return finalpath; // Return the full path if executable is found
        }
        free(finalpath); // Free allocated memory if not found
        i++;
    }
    ft_free_split(path_env);
    return NULL;
}