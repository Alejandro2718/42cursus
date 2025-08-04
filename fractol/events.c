/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:29:00 by alejjime          #+#    #+#             */
/*   Updated: 2025/08/04 18:31:05 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connec, fractol->img.img_pit);
	mlx_destroy_window(fractol->mlx_connec, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connec);
	free(fractol->mlx_connec);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations_definition += 10;
	else if (keysym == XK_minus)
	{
		if (fractol->iterations_definition > 10)
			fractol->iterations_definition -= 10;
	}
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}
