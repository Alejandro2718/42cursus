/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/11 15:34:18 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int main(void)
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "My Window");
    
    // Draw stuff
    
    mlx_loop(mlx);
    return (0);
}