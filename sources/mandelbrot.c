/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:39:23 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 17:58:31 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include <stdio.h>

static void    img_pix_put(t_img *image, int x, int y, int color)
{
    char    *pixel;

	pixel = image->data + (y * image->line_len + x * (image->bpp / 8));
    *(unsigned int *)pixel = color;
}

void	zoom_in(t_img *img, double factor, double mouse_x, double mouse_y)
{    
	double range_x;
    double range_y;
    double center_x;
    double center_y; 
	
	img->it_max += 200 ;
	range_x = img->x2 - img->x1;
	range_y = img->y2 - img->y1;
	center_x = img->x1 + mouse_x / img->zoom;
	center_y = img->y1 + mouse_y / img->zoom;
    img->x1 = center_x - (range_x / factor) / 2.0;
    img->x2 = center_x + (range_x / factor) / 2.0;
    img->y1 = center_y - (range_y / factor) / 2.0;
    img->y2 = center_y + (range_y / factor) / 2.0;
    img->zoom *= factor;
}

void	init_mandelbrot(t_img *img)
{
	img->x1 = -2.0;
	img->x2 = 0.6;
	img->y1 = -1.2;
	img->y2 = 1.2;
	img->it_max = 2000;
	img->zoom = 450;
}

void	mandelbrot(t_img *img)
{
	double			image_x, image_y, c_r, c_i, z_r, z_i, tmp;
	unsigned int	x, y, i;
	
	x = 0;
	image_x = (img->x2 - img->x1) * img->zoom;
	image_y = (img->y2 - img->y1) * img->zoom;
	printf("x = %f \n", image_x);
	printf("y = %f \n", image_y);
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
				//img_pix_put(img, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
