/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <aroullea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:15:58 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/27 12:20:09 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	init_julia(t_data *data)
{
	data->x1 = -2.0;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->it_max = 300;
	data->zoom = 300;
}

unsigned int	calc_julia(float z_r, float z_i, t_data *data)
{
	unsigned int	i;
	float			tmp;
	float			c_r;
	float			c_i;

	i = 0;
	c_r = 0.285;
	c_i = 0.013;
	while (((z_r * z_r) + (z_i * z_i) < 4) && (i < data->it_max))
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}

void	julia(t_data *data, float z_r, float z_i, unsigned int i)
{
	float			image_x;
	float			image_y;
	float			tmp;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	image_x = (data->x2 - data->x1) * data->zoom;
	image_y = (data->y2 - data->y1) * data->zoom;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			z_r = x / data->zoom + data->x1;
			z_i = y / data->zoom + data->y1;
			i = calc_julia(z_r, z_i, data);
			if (i == data->it_max)
				img_pix_put(data, x, y, 0x000000);
			else
				img_pix_put(data, x, y, get_color(i, data->it_max));
			y++;
		}
		x++;
	}
}
