/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:33 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/30 18:55:49 by alejjime         ###   ########.fr       */
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
}			t_fractol;

void		fractol_init(t_fractol *fractol);
#endif