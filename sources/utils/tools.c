/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:56:16 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/30 05:56:21 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

unsigned int	get_color(unsigned int i, unsigned int it_max)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = ((double)i / it_max) + 0.03;
	r = (9 * (1 - t) * t * t * t * 255);
	g = (15 * (1 - t) * (1 - t) * t * t * 255);
	b = (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	ft_free(char **result)
{
	int		i;

	i = 0;
	if (result != NULL)
	{
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
}
