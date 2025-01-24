/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:18:53 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 17:38:26 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int main(int argc, char *argv[])
{
	t_win  window;
	t_img  image;

	if (!(check_arg(argc,argv)))
	{
		image = create_window(&window);
		mlx_key_hook(window.win_ptr, &read_keys, &image);
		mlx_mouse_hook(window.win_ptr, &read_mouse, &image);
		mlx_hook(window.win_ptr, 17, 0, exit_window, &image);
		init_mandelbrot(&image);
		mandelbrot(&image);
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, 0, 0);
		mlx_loop(window.mlx_ptr);
	}
	return (0);
}
