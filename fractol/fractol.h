/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:33 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/21 19:00:34 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 400
# define MIN_RE -2.0
# define MAX_RE 2.0
# define MIN_IM -1.5
# define MAX_IM 1.5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// Utility functions
void		ft_put_pixel(t_data *img, int x, int y, int color);
double		map_pixel_to_real(int x, int width);
double		map_pixel_to_imag(int y, int height);
int			map_complex_to_color(double re, double im);

#endif