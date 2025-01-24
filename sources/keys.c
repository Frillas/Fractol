/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:51 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/23 14:32:32 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_window(img);
	else
		return (-1);
	return (0);
}
