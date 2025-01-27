/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:21:02 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/27 16:55:29 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	handle_error(void)
{
	write(1, "for mandlebrot --> ./fractol m or ./fractol mandlebrot\n", 55);
	write(1, "for julia --> ./fractol j or ./fractol julia ", 45);
	write(1, "with 2 numbers between -2 and 2 \n", 33);
	exit(EXIT_FAILURE);
}

int	is_empty(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv != NULL && argv[i] != NULL)
	{
		if (argv[i][j] != ' ')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE)
}
