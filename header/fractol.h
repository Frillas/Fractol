/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:57 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/30 04:28:34 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "type.h"

# define ZOOM_UP 4 
# define ZOOM_DOWN 5 
# define ESC 65307 

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				h;
	int				w;
	int				bpp;
	int				endian;
	int				line_len;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	unsigned int	it_max;
	int				fract_choice;
	double			c_r;
	double			c_i;
}	t_data;
//window.c
void			create_window(t_data *data);
int				exit_window(t_data *data);
void			zoom(t_data *data, double factor, double x, double y);
void			fract_reload(t_data *data);
//keys.c
int				read_keys(int key_pressed, void *param);
int				read_mouse(int button, int mouse_x, int mouse_y, void *param);
//mandelbrot.c
void			mandelbrot(t_data *d, double c_r, double c_i, unsigned int i);
void			init_mandelbrot(t_data *data);
//julia.c
void			julia(t_data *data, double z_r, double z_i, unsigned int i);
void			init_julia(t_data *data);
//parsing.c
int				check_arg(int argc, char *argv[], t_data *data);
//tools.c
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			img_pix_put(t_data *data, int x, int y, int color);
unsigned int	get_color(unsigned int i, unsigned int it_max);
t_bool			ft_atof_valid(const char *s, double *value, t_bool res, int i);
void			ft_free(char **result);
//error.c
void			handle_error(void);
int				is_empty(char *src);
//split.c
char			**ft_split(char const *s, char c);
#endif
