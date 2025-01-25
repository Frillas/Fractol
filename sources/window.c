/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:22:40 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/25 07:09:48 by aroullea         ###   ########.fr       */
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

t_data	create_window(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		exit (EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 780, 720, "FRACTOL");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		exit(EXIT_FAILURE);
	}
	new_img(780, 720, &data);
	return (data);
}

int	exit_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
