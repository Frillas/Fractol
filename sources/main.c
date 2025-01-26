/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:18:53 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/26 19:20:34 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	fractal_choice(char *argv[], t_data *data)
{
	if (!ft_strncmp(argv[1], "m", 2) || !ft_strncmp(argv[1], "mendelbrot", 11))
	{
		init_mandelbrot(data);
		mandelbrot(data, 0.0, 0.0, 0);
	}
	else if (!ft_strncmp(argv[1], "j", 2) || !ft_strncmp(argv[1], "julia", 6))
	{
		julia(data, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!(check_arg(argc, argv)))
	{
		data = create_window();
		mlx_key_hook(data.win_ptr, &read_keys, &data);
		mlx_mouse_hook(data.win_ptr, &read_mouse, &data);
		mlx_hook(data.win_ptr, 17, 0, exit_window, &data);
		fractal_choice(argv, &data);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
