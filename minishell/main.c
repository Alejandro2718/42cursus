/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:04:47 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 18:26:32 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	disable_ctrl(void)
{
	struct termios	t;

	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

static void	shell_process(t_shell *shell)
{
	char			*rl;
	t_token_list	*tokens;

	while (1)
	{
		signal_int(PROMPT);
		signal_ignore_quit();
		rl = readline("\x1b[32mPrompt > \x1b[m");
		if (!rl)
			break ;
		add_history(rl);
		tokens = lexer(rl);
		if (!tokens)
			free(rl);
		shell->cmd_list = create_list_from_tokens(tokens);
		if (shell->cmd_list)
		{
			expand_cmd_exit_status(shell->cmd_list, shell->exit_status);
			parsing(shell);
			free_cmd_list(&shell->cmd_list);
		}
		free_token_list(tokens);
		free(rl);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell			*shell;

	(void)ac;
	(void)**av;
	shell = malloc(sizeof(t_shell));
	shell->env = env;
	shell->exit_status = 0;
	disable_ctrl();
	shell_process(shell);
	free(shell);
	return (0);
}
