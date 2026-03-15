/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:29:01 by artem             #+#    #+#             */
/*   Updated: 2025/11/29 01:00:34 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	interrupt(int sig);
void	interrupt_with_new_line(int sig);
void	interrupt_heredoc(int sig);
void	quit_message(int sig);

void	signal_int(t_signal_type sig_type)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (sig_type == PROMPT)
		sa.sa_handler = interrupt_with_new_line;
	else if (sig_type == EXEC)
		sa.sa_handler = interrupt;
	else if (sig_type == HEREDOC)
		sa.sa_handler = interrupt_heredoc;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}

void	signal_ignore_quit(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
}

void	signal_quit(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = quit_message;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
}
