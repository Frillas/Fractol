/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:56:16 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/27 12:15:22 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

unsigned int	get_color(unsigned int i, unsigned int it_max)
{
	float			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = ((float)i / it_max) + 0.03;
	r = (9 * (1 - t) * t * 255);
	g = (15 * (1 - t) * (1 - t) * t * t * 255);
	b = (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void    zoom(t_data *data, double factor, double mouse_x, double mouse_y)
{
    float   range_x;
    float   range_y;
    float   center_x;
    float   center_y;

    data->it_max += 10;
    range_x = data->x2 - data->x1;
    range_y = data->y2 - data->y1;
    center_x = data->x1 + mouse_x / data->zoom;
    center_y = data->y1 + mouse_y / data->zoom;
    data->x1 = center_x - (range_x / factor) / 2.0;
    data->x2 = center_x + (range_x / factor) / 2.0;
    data->y1 = center_y - (range_y / factor) / 2.0;
    data->y2 = center_y + (range_y / factor) / 2.0;
    data->zoom *= factor;
	fract_reload(data);
}

void	fract_reload(t_data *data)
{
	if (data->fract_choice == 1)
		mandelbrot(data, 0.0, 0.0, 0);
	if (data->fract_choice == 2)
		julia(data, 0.0, 0.0, 0);
}
