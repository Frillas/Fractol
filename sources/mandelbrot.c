/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:23 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/25 11:18:50 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	zoom_in(t_data *data, double factor, double mouse_x, double mouse_y)
{
	float	range_x;
	float	range_y;
	float	center_x;
	float	center_y;

	data->it_max += 100 ;
	range_x = data->x2 - data->x1;
	range_y = data->y2 - data->y1;
	center_x = data->x1 + mouse_x / data->zoom;
	center_y = data->y1 + mouse_y / data->zoom;
	data->x1 = center_x - (range_x / factor) / 2.0;
	data->x2 = center_x + (range_x / factor) / 2.0;
	data->y1 = center_y - (range_y / factor) / 2.0;
	data->y2 = center_y + (range_y / factor) / 2.0;
	data->zoom *= factor;
}

void	init_mandelbrot(t_data *data)
{
	data->x1 = -2.0;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->it_max = 200;
	data->zoom = 300;
}

unsigned int	calc_mendelbrot(float c_r, float c_i, t_data *data)
{
	unsigned int	i;
	float			tmp;
	float			z_r;
	float			z_i;

	z_r = 0;
	z_i = 0;
	i = 0;
	while (((z_r * z_r) + (z_i * z_i) < 4) && (i < data->it_max))
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data, float c_r, float c_i, unsigned int i)
{
	float			image_x;
	float			image_y;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	image_x = (data->x2 - data->x1) * data->zoom;
	image_y = (data->y2 - data->y1) * data->zoom;
	while (x < image_x)
	{
		y = 0;
		c_r = x / data->zoom + data->x1;
		while (y < image_y)
		{
			c_i = y / data->zoom + data->y1;
			i = calc_mendelbrot(c_r, c_i, data);
			if (i == data->it_max)
				img_pix_put(data, x, y, 0x000000);
			else
				img_pix_put(data, x, y, i * 258);
			y++;
		}
		x++;
	}
}
