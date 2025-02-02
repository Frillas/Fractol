/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:21:02 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/31 22:42:55 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	handle_error(void)
{
	write(2, "for mandlebrot --> ./fractol m or ./fractol mandlebrot\n", 55);
	write(2, "for julia --> ./fractol j or ./fractol julia ", 45);
	write(2, "with 2 numbers between -2 and 2 \n", 33);
	exit(EXIT_FAILURE);
}

int	is_empty(char *src)
{
	int	i;

	i = 0;
	if (src != NULL)
	{
		while (src[i] != '\0')
		{
			if (src[i] != ' ')
				return (EXIT_SUCCESS);
			i++;
		}
	}
	return (EXIT_FAILURE);
}
