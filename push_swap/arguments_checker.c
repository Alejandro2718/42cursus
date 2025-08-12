/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:38:59 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/12 21:08:37 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ---------------- basic duplicate checker by string (legacy) ---------------
int	int_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if ((ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]))) == 0
				&& ft_strlen(argv[i]) == ft_strlen(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// ---------------- robust numeric validation helpers ------------------------

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_str_numeric(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (is_sign(s[i]))
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_long_in_range(const char *s, long *out)
{
	int		neg;
	long	res;
	int		i;

	if (!is_str_numeric(s))
		return (0);
	i = 0;
	neg = 1;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	res = 0;
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if (neg == 1 && res > INT_MAX)
			return (0);
		if (neg == -1 && -res < INT_MIN)
			return (0);
		i++;
	}
	*out = res * neg;
	return (1);
}

// ---------------- API kept for other uses ----------------------------------

int	check_arg(char *argv)
{
	long	val;

	return (parse_long_in_range(argv, &val));
}

// ---------------- parsing and building the stack ---------------------------

static void	free_tokens(char **toks)
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

static char	**dup_args(int argc, char **argv)
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

static int	has_numeric_duplicates(long *vals, int n)
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

int	parse_and_build(int argc, char **argv, t_node **head_a)
{
	char	**toks;
	int		count;
	int		i;
	long	*vals;
	long	v;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		toks = ft_split(argv[1], ' ');
		if (!toks || !toks[0])
		{
			free_tokens(toks);
			return (0);
		}
	}
	else
		toks = dup_args(argc, argv);
	if (!toks)
		return (0);
	count = 0;
	while (toks[count])
		count++;
	vals = (long *)malloc(sizeof(long) * count);
	if (!vals)
	{
		free_tokens(toks);
		return (0);
	}
	i = 0;
	while (i < count)
	{
		if (!parse_long_in_range(toks[i], &v))
		{
			free(vals);
			free_tokens(toks);
			return (0);
		}
		vals[i] = v;
		i++;
	}
	if (has_numeric_duplicates(vals, count))
	{
		free(vals);
		free_tokens(toks);
		return (0);
	}
	i = 0;
	while (i < count)
		insert_end(head_a, (int)vals[i++]);
	free(vals);
	free_tokens(toks);
	return (1);
}
