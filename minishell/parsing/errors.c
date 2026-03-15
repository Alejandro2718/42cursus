/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:54:09 by adanilov          #+#    #+#             */
/*   Updated: 2025/11/29 18:20:12 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	if_not_found(t_cmd_list *cmd_list)
{
	if (ft_strchr(cmd_list->cmd[0], '='))
		return (0);
	ft_putstr_fd(cmd_list->cmd[0], 2);
	if (ft_strchr((cmd_list->cmd[0]), '/'))
		ft_putstr_fd(" : No such file or directory\n", 2);
	else
		ft_putstr_fd(" : command not found\n", 2);
	return (127);
}

int	if_dir(t_cmd_list *cmd_list, char *exe_path)
{
	struct stat	path_stat;

	if (stat(exe_path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd(cmd_list->cmd[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	else
		perror(cmd_list->cmd[0]);
	return (126);
}
