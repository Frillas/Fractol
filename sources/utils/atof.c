/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:35:58 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/30 04:27:34 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

static int	number_sign(char s, int *i)
{
	int	sign;

	sign = 1;
	if (s == '+' || s == '-')
	{
		if (s == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	convert_number(const char *s, int *j, t_bool *res)
{
	double	div;
	int		i;
	double	number;

	i = *j;
	div = 10;
	number = 0;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			*res = TRUE;
			number = number + ((s[i] - '0') / div);
			div *= 10;
			i++;
		}
	}
	*j = i;
	return (number);
}

t_bool	ft_atof_valid(const char *s, double *value, t_bool res, int i)
{
	int		sign;
	double	number;

	sign = 1;
	number = 0;
	res = FALSE;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	sign = number_sign(s[i], &i);
	if (s[i] >= '0' && s[i] <= '2')
	{
		*value = s[i++] - '0';
		if (s[i] == '\0')
			res = TRUE;
	}
	number = convert_number(s, &i, &res);
	if (s[i] != '\0')
		return (FALSE);
	if (res == TRUE)
	{
		*value = (*value + number) * sign;
		return (TRUE);
	}
	return (FALSE);
}
