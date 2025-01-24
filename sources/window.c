/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:22:40 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 11:51:57 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	create_window(t_win *window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		exit (EXIT_FAILURE);
	window->win_ptr = mlx_new_window(window->mlx_ptr, 780, 720, "FRACTOL");
	if (window->win_ptr == NULL)
	{
		free(window->mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

t_img   new_img(int w, int h, t_win *window)
{
    t_img   image;

    image.win = window;
    image.img_ptr = mlx_new_image(window->mlx_ptr, w, h);
    if (image.img_ptr == NULL)
        exit_window(&image);
    image.data = mlx_get_data_addr(image.img_ptr, &(image.bpp),
        &(image.line_len), &(image.endian));
    image.w = w;
    image.h = h;
    return (image);
}

int	exit_window(t_img *image)
{
	mlx_destroy_image(image->win->mlx_ptr, image->img_ptr);
	mlx_destroy_window(image->win->mlx_ptr, image->win->win_ptr);
	mlx_destroy_display(image->win->mlx_ptr);
	free(image->win->mlx_ptr);
	exit(EXIT_SUCCESS);
}
