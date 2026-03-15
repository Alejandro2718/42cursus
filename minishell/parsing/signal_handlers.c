/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:44:36 by artem             #+#    #+#             */
/*   Updated: 2025/11/29 01:00:54 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	interrupt(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	interrupt_with_new_line(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	interrupt(sig);
	rl_redisplay();
}

void	interrupt_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	interrupt(sig);
}

void	quit_message(int sig)
{
	(void)sig;
	write(2, "Quit (core dumped)\n", 20);
}
