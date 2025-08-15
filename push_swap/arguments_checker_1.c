/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:44:18 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:47:24 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_tokens(int argc, char **argv)
{
	char	**toks;

	if (argc == 2)
	{
		toks = ft_split(argv[1], ' ');
		if (!toks || !toks[0])
		{
			free_tokens(toks);
			return (NULL);
		}
	}
	else
		toks = dup_args(argc, argv);
	return (toks);
}

static int	count_tokens(char **toks)
{
	int	count;

	count = 0;
	while (toks[count])
		count++;
	return (count);
}

static int	parse_tokens_to_values(char **toks, int count, long **vals)
{
	int		i;
	long	v;

	*vals = (long *)malloc(sizeof(long) * count);
	if (!*vals)
		return (0);
	i = 0;
	while (i < count)
	{
		if (!parse_long_in_range(toks[i], &v))
		{
			free(*vals);
			return (0);
		}
		(*vals)[i] = v;
		i++;
	}
	return (1);
}

int	parse_and_build(int argc, char **argv, t_node **head_a)
{
	char	**toks;
	int		count;
	long	*vals;

	if (argc < 2)
		return (1);
	toks = get_tokens(argc, argv);
	if (!toks)
		return (0);
	count = count_tokens(toks);
	if (!parse_tokens_to_values(toks, count, &vals))
	{
		free_tokens(toks);
		return (0);
	}
	if (has_numeric_duplicates(vals, count))
	{
		free(vals);
		free_tokens(toks);
		return (0);
	}
	build_stack(head_a, vals, count);
	free(vals);
	free_tokens(toks);
	return (1);
}
