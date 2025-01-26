/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:57 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/26 19:10:47 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>

#define ZOOM_UP 4 
#define ZOOM_DOWN 5 
#define ESC 65307 //"escape"
#define ENTER 65293 // "enter"
#define FOLLOW 102 // "f"
#define COLOR 99 // "c"
#define UP 65362 // "UP"
#define DOWN 65364// "DOWN"
#define RAND_COLOR 114 // "r"

typedef struct s_data
{   
    void	*mlx_ptr;
    void	*win_ptr;
    void	*img_ptr;
    char	*addr;
    int		h;
    int		w;
    int		bpp;
    int		endian;
    int		line_len;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	int		it_max;
} t_data;
//window.c
t_data			create_window(void);
int				exit_window(t_data *data);
//keys.c
int     		read_keys(int key_pressed, void *param);
int				read_mouse(int button, int mouse_x, int mouse_y, void *param);
//mandelbrot.c
void			mandelbrot(t_data *data, float c_r, float c_i, unsigned int i);
void    		init_mandelbrot(t_data *data);
void			zoom_in(t_data *data, double factor, double mouse_x, double mouse_y);
//julia.c
void			julia(t_data *data, unsigned int i);
//parsing.c
int				check_arg(int argc, char *argv[]);
//tools.c
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			img_pix_put(t_data *data, int x, int y, int color);
unsigned int	get_color(unsigned int i, unsigned int it_max);
#endif
