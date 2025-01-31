/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:23 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/31 23:09:45 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	init_mandelbrot(t_data *data)
{
	data->x1 = -2.0;
	data->x2 = 0.6;
	data->y1 = -1.2;
	data->y2 = 1.2;
	data->it_max = 100;
	data->zoom = 300;
}

static unsigned int	calc_mendelbrot(double c_r, double c_i, t_data *data)
{
	unsigned int	i;
	double			tmp;
	double			z_r;
	double			z_i;

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

void	mandelbrot(t_data *data, double c_r, double c_i, unsigned int i)
{
	double			image_x;
	double			image_y;
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
				img_pix_put(data, x, y, get_color(i, data->it_max));
			y++;
		}
		x++;
	}
}
