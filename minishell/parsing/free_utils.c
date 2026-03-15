/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:47:43 by adanilov          #+#    #+#             */
/*   Updated: 2025/11/29 17:24:48 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_cmd_list(t_cmd_list **list)
{
	t_cmd_list	*cur;
	t_cmd_list	*next;
	t_redir		*cur_rd;
	t_redir		*next_rd;

	cur = *list;
	while (cur)
	{
		next = cur->next;
		cur_rd = cur->redir;
		while (cur_rd)
		{
			next_rd = cur_rd->next;
			free(cur_rd->filename);
			free(cur_rd);
			cur_rd = next_rd;
		}
		if (cur->cmd)
			free_cmd(cur->cmd);
		free(cur);
		cur = next;
	}
	*list = NULL;
}

void	free_split(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
