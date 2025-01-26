/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:50:07 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/26 17:29:28 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h> //ELIMINAR - SOLO PARA PRUEBAS
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		letter_in_set(char letter, const char *set);
void	print_convertion(char *s, va_list args);
void	print_char(char a);

#endif