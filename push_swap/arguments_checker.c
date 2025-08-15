/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:38:59 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/15 17:24:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	process_sign(const char *s, int *neg)
{
	int	i;

	i = 0;
	*neg = 1;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		*neg = -1;
		i++;
	}
	return (i);
}

static int	convert_to_long(const char *s, int start, int neg, long *result)
{
	long	res;
	int		i;

	res = 0;
	i = start;
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if (neg == 1 && res > INT_MAX)
			return (0);
		if (neg == -1 && (-res) < INT_MIN)
			return (0);
		i++;
	}
	*result = res * neg;
	return (1);
}

int	parse_long_in_range(const char *s, long *out)
{
	int	neg;
	int	start;

	if (!is_str_numeric(s))
		return (0);
	start = process_sign(s, &neg);
	return (convert_to_long(s, start, neg, out));
}
