/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:45:34 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/27 18:21:58 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	add_number(float value, t_data *data)
{
	
}

void	build_args(char **numbers, t_data *data)
{
	int		i;
	float	value;
	t_bool	res;

	i = 0;
	res = FALSE;
	while (numbers[i] != NULL)
	{
		value = 0;
		res = ft_atoi_valid(result[i], &value, res);
		if (!res || ((value > 2.0) || (value < -2.0)))
		{
			ft_free(numbers);
			handle_error();
		}
		add_number(value, data);
	}
}

void	parsing(int argc, char *argv[], t_data *data)
{
	int		i;
	int		value;
	char	**numbers;
	t_bool	res;

	i = 2;
	res = FALSE;
	while (i < argc)
	{
		if (!is_empty (argv[i]))
			handle_error();
		numbers = ft_split(argv[i], ' ');
		if (numbers == NULL)
		{
			write(2, "Split : memory allocation failed\n", 34);
			exit(EXIT_FAILURE);
		}
		build_args(numbers);
	}
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 1)
		handle_error();
	else if ((argc > 2 && argc <= 4) && (!ft_strncmp(argv[1], "j", 2) 
			|| !ft_strncmp(argv[1], "julia", 6)))
	{
		parsing(argc, argv, data);	
		return (0);
	}
	else if (argc == 2 && (!ft_strncmp(argv[1], "m", 2)
			|| !ft_strncmp(argv[1], "mandelbrot", 11)))
		return (0);
	else
		handle_error();
}
