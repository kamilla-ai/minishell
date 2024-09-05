/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:56:17 by krazikho          #+#    #+#             */
/*   Updated: 2024/09/05 12:02:08 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void configure_terminal_behavior() {
    struct termios term;

    tcgetattr(STDIN_FILENO, &term);         // Get terminal attributes
    term.c_lflag &= ~ECHOCTL;               // Disable ^C and ^\ echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &term); // Set new terminal attributes
}

void sigint_handler(int sig) {
    (void)sig; 
    // write(1, "\n", 1);  
    // rl_replace_line("", 0);
    // rl_on_new_line();
    write(1, "\nminishell$ ", 13);
    // rl_redisplay(); 
}

void sigquit_handler(int sig) {
    (void)sig;
    write(1, "", 1);
}