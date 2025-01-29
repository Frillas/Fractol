/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:45:34 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/29 12:19:10 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	add_number(float value, t_data *data)
{
	static int	i;

	if (i == 0)
	{
		data->c_r = value;
		i++;
		return ;
	}
	if (i == 1)
	{
		data->c_i = value;
		return ;
	}
}

void	build_args(char **numbers, t_data *data, int argc)
{
	int		i;
	float	value;
	t_bool	res;

	i = 0;
	res = FALSE;
	while (numbers[i] != NULL)
	{
		value = 0;
		res = ft_atof_valid(numbers[i], &value, res, 0);
		if (!res || ((value > 2.0) || (value < -2.0)) || i > 1)
		{
			ft_free(numbers);
			handle_error();
		}
		add_number(value, data);
		i++;
	}
	if (argc == 3 && numbers[1] == NULL)
	{
		ft_free(numbers);
		handle_error();
	}
	ft_free(numbers);
}

void	parsing(int argc, char *argv[], t_data *data)
{
	int		i;
	char	**numbers;
	t_bool	res;

	i = 2;
	res = FALSE;
	while (i < argc)
	{
		if (is_empty (argv[i]))
			handle_error();
		numbers = ft_split(argv[i], ' ');
		if (numbers == NULL)
		{
			write(2, "Split : memory allocation failed\n", 34);
			exit(EXIT_FAILURE);
		}
		build_args(numbers, data, argc);
		i++;
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
	return (1);
}
