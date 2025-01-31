/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:50:07 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/31 20:38:13 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		print_convertion(char *s, va_list args);
int		print_char(char a);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(int n, int base, char *hex);
int		print_p_hex(char *s, va_list args);
int		leng(unsigned long long n, int base);
char	*ft_strrev(char *str);
int		print_x_hex(char *s, va_list args, char *base);
int		print_u(char *s, va_list args);

#endif
