/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:56:16 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/28 12:33:55 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

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
	float			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = ((float)i / it_max) + 0.03;
	r = (9 * (1 - t) * t * t * t * 255);
	g = (15 * (1 - t) * (1 - t) * t * t * 255);
	b = (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

t_bool	ft_atof_valid(const char *s, float *value, t_bool res)
{
	int		i;
	int		sign;
	int		div;
	float	number;

	i = 0;
	sign = 1;
	number = 0;
	res = FALSE;
	div = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if (s[i] >= '0' && s[i] <= '2')
	{
		*value = s[i++] - '0';
		if (s[i] == '\0')
			return (TRUE);
	}
	else
		return (FALSE);
	if (s[i] == '.' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
	{
		res = TRUE;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && (res == TRUE))
	{
		number = (number * 10) + (s[i++] - '0');
		if (number == 0)
			div++;
		if (number < 0 || number > 2417483646 || *value >= 2)
			return (FALSE);
	}
	if (s[i] != '\0')
		return (FALSE);
	while ((number >= 1) && (res == TRUE) || (div > 0))
	{
		if (number >= 1)
			number = number / 10;
		if (div > 0)
		{	
			number = number / 10;
			div--;
		}
	}
	*value = (*value + number) * sign;
	if ((res == TRUE) && (s[i] == '\0'));
		return (TRUE);
	return (FALSE);
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
