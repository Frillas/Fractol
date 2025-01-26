/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:45:34 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/26 19:21:14 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	check_arg(int argc, char *argv[])
{
	if (argc < 2)
		exit (EXIT_FAILURE);
	if (!ft_strncmp(argv[1], "m", 2) || !ft_strncmp(argv[1], "mendelbrot", 11))
		return (0);
	else if (!ft_strncmp(argv[1], "j", 2) || !ft_strncmp(argv[1], "julia", 6))
		return (0);
	else
		exit (EXIT_FAILURE);
}
