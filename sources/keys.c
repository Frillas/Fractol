/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:51 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 17:51:41 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_window(img);
	else
		return (-1);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	t_img	*img;
	
	img = (t_img *) param;
	(void)mouse_x;
	(void)mouse_y;
	if (button == ZOOM_UP)
		zoom_in(img, 1.9, 550.21, 492.12);
	mandelbrot(img);
	mlx_put_image_to_window(img->win->mlx_ptr, img->win->win_ptr, img->img_ptr, 0, 0);
	return (0);
}
