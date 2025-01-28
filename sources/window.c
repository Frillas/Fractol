/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:22:40 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/28 11:07:58 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	new_img(int w, int h, t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, w, h);
	if (data->img_ptr == NULL)
		exit_window(data);
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
			&(data->line_len), &(data->endian));
	data->w = w;
	data->h = h;
}

void	create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 780, 720, "FRACTOL");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	new_img(780, 720, data);
}

int	exit_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	zoom(t_data *data, double factor, double mouse_x, double mouse_y)
{
	float	range_x;
	float	range_y;
	float	center_x;
	float	center_y;

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
