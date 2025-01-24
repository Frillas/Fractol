/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:23 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 12:00:39 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static void    img_pix_put(t_img *image, int x, int y, int color)
{
    char    *pixel;

	pixel = image->data + (y * image->line_len + x * (image->bpp / 8));
    *(unsigned int *)pixel = color;
}

void	mandelbrot(t_img *img)
{
	double			image_x, image_y, c_r, c_i, z_r, z_i, tmp;
	unsigned int	x, y, i;
	
	x = 0;
	img->x1 = -2.0;
	img->x2 = 0.6;
	img->y1 = -1.2;
	img->y2 = 1.2;
	img->it_max = 500;
	img->zoom = 300;
	image_x = (img->x2 - img->x1) * img->zoom;
	image_y = (img->y2 - img->y1) * img->zoom;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / img->zoom + img->x1;
			c_i = y / img->zoom + img->y1;
			z_r = 0;
			z_i = 0;
			i = 0;

			while (((z_r * z_r) + (z_i * z_i) < 4) && (i < img->it_max))
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == img->it_max)
				img_pix_put(img, x, y, 0x000000);
			else
				img_pix_put(img, x, y, i*2000/img->it_max);
			y++;
		}
		x++;
	}
}
