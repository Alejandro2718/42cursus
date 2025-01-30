/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:50:07 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/30 19:44:33 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *string, ...);
static int	letter_in_set(char letter, const char *set);
int			print_convertion(char *s, va_list args);
int			print_char(char a);
int			ft_putstr_fd(char *s, int fd);
char		*ft_itoa_base(int n, int base, char *hex);

#endif