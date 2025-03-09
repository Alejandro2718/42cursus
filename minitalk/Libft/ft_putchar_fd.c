/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:33:57 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/05 16:29:15 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function outputs a character
in the given files descriptor 'fd'
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
