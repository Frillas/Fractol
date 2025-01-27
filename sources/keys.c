/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:51 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/27 10:50:28 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	read_keys(int key_pressed, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key_pressed == ESC || !data)
		exit_window(data);
	else
		return (-1);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	(void)mouse_x;
	(void)mouse_y;
	if (button == ZOOM_UP)
		zoom(data, 2, mouse_x, mouse_y);
	else if (button == ZOOM_DOWN)
		zoom(data, 0.5, mouse_x, mouse_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
