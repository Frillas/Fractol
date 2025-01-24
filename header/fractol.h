/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:57 by aroullea          #+#    #+#             */
/*   Updated: 2025/01/24 17:31:32 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>

#define ZOOM_UP 4 
#define ESC 65307 //"escape"
#define ENTER 65293 // "enter"
#define FOLLOW 102 // "f"
#define COLOR 99 // "c"
#define UP 65362 // "UP"
#define DOWN 65364// "DOWN"
#define RAND_COLOR 114 // "r"

typedef struct s_win
{ 
    void    *mlx_ptr;
    void    *win_ptr;
}   t_win;

typedef struct s_img
{   
    t_win   *win;
    void    *img_ptr;
    char    *data;
    int     h;
    int     w;
    int     bpp;
    int     endian;
    int     line_len;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	unsigned int	it_max;
} t_img;
//window.c
t_img	create_window(t_win *window);
int		exit_window(t_img *image);
//keys.c
int     read_keys(int key_pressed, void *param);
int		read_mouse(int button, int mouse_x, int mouse_y, void *param);
//mandelbrot.c
void	mandelbrot(t_img *img);
void    init_mandelbrot(t_img *img);
void	zoom_in(t_img *img, double factor, double mouse_x, double mouse_y);
//parsing.c
int		check_arg(int argc, char *argv[]);
//tools.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
