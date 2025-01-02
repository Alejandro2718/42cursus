/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:32:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/02 20:17:46 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function check if "pr" is in printable by checking
the ascii value from ' '(space) to '~', return (1) if "pr" is
printable and return (0) if not.
*/
int	ft_isprint(int pr)
{
	if (pr >= ' ' && pr <= '~')
	{
		return (1);
	}
	return (0);
}
