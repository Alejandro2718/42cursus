/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:33 by alejjime          #+#    #+#             */
/*   Updated: 2025/05/03 18:06:57 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 400

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0xc842f5

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_pit;
	char	*pixel_pit;
	int		bits_p_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connec;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
}			t_fractol;

void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);
double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
#endif