/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:45:53 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 18:27:03 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef enum e_signal_type
{
	PROMPT,
	EXEC,
	HEREDOC
}						t_signal_type;

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_OUT,
	T_REDIR_OUT_APPEND,
	T_REDIR_IN,
	T_HEREDOC,
	T_END
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	int					no_space_before;
	struct s_token		*next;
}						t_token;

typedef struct s_token_list
{
	struct s_token		*head;
	struct s_token		*tail;
}						t_token_list;

typedef struct s_redir
{
	t_token_type		type;
	char				*filename;
	struct s_redir		*next;
}						t_redir;

typedef struct s_cmd_list
{
	char				**cmd;
	struct s_redir		*redir;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_shell
{
	t_cmd_list			*cmd_list;
	char				**env;
	int					exit_status;
	int					fd;
	pid_t				last_pid;
}						t_shell;

t_token_list			*init_token_list(void);
void					free_token_list(t_token_list *list);
void					append_token(t_token_list *list, t_token *token);
t_token					*create_token(void);

void					skip_whitespace(const char *prompt, int *i);
t_token					*read_operator(const char *prompt, int *i);
t_token					*read_single_quoted(const char *prompt, int *i);
t_token					*read_double_quoted(const char *prompt, int *i);

t_token					*read_word(const char *prompt, int *i);

char					*double_quoted_substr(char const *prompt,
							unsigned int start, size_t len);
char					*single_quoted_substr(char const *prompt,
							unsigned int start, size_t len);
char					process_escape_char(char c);
void					case_backslash(const char *prompt, unsigned int *i);
char					*extract_var_name(const char *prompt, unsigned int *i);
char					*get_env_value(char *var_name);
char					*expand_variable(const char *prompt, unsigned int *i);
char					*expand_word_variables(const char *word);
char					*append_str(char *result, char *to_add);
int						dispatch_next_token(const char *prompt, int *i,
							t_token_list *list, int no_space);

t_token_list			*lexer(const char *prompt);

// ..........Only for tests
void					list_test(t_token_list *lst);
void					list_parsed_test(t_cmd_list *lst);
// ..........

int						is_redir(t_token_type type);
int						token_size(t_token *lst);
int						redir_size(t_token *lst);
char					*expand_exit_status(char *str, int exit_status);
void					expand_cmd_exit_status(t_cmd_list *cmd_list,
							int exit_status);
t_cmd_list				*create_list_from_tokens(t_token_list *tokens);
void					init_heredoc(t_shell *shell);
void					redirections(t_token_type s_redir, char *file, int fd);
void					execute_child_process(t_shell *shell, int *p,
							int prev_p);
void					parsing(t_shell *shell);
int						builtin_cmd(t_cmd_list *cmd_list, char **envp,
							int exit_status);
int						is_builtin_parent(char *cmd);
int						is_builtin_child(char *cmd);
void					free_cmd_list(t_cmd_list **list);
void					free_split(char **arr);
void					signal_int(t_signal_type sig_type);
void					signal_quit(void);
void					signal_ignore_quit(void);

#endif
