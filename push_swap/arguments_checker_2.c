/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:24:05 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:47:24 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **toks)
{
	int	i;

	if (!toks)
		return ;
	i = 0;
	while (toks[i])
	{
		free(toks[i]);
		i++;
	}
	free(toks);
}

int	has_numeric_duplicates(long *vals, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] == vals[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**dup_args(int argc, char **argv)
{
	char	**toks;
	int		i;

	toks = (char **)malloc(sizeof(char *) * (argc));
	if (!toks)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		toks[i - 1] = ft_strdup(argv[i]);
		if (!toks[i - 1])
		{
			free_tokens(toks);
			return (NULL);
		}
		i++;
	}
	toks[argc - 1] = NULL;
	return (toks);
}

void	build_stack(t_node **head_a, long *vals, int count)
{
	int	i;

	i = 0;
	while (i < count)
		insert_end(head_a, (int)vals[i++]);
}
