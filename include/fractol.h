/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:21:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/17 18:21:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <sys/types.h>

# include "structs.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define FALSE 0
# define TRUE 1
# define WRONG_NUMBER_OF_FILES 2
# define BAD_FILE 3
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define CELTIC_MANDELBROT 4
# define CUBE_MANDELBROT 5
# define PRETTY_FRACTAL 6
# define PYTHAGORAS_TREE 7
# define SIERPINSKI_TRIANGLE 8

# define THREAD_MAX 4
# define W_TITLE "Fractol by dadavyde"

# define ABS(Value) (((Value) < 0) ? (Value) * (-1) : (Value))

# define WHITE 0
# define RED 1
# define GREEN 2
# define BLUE 3
# define TREE_X 600
# define TREE_Y 1000
# define PI (M_PI / 180)
# define A_SIZE 200

# define PLUS_KEY 69
# define MINUS_KEY 78
# define ASTERISK_KEY 67
# define ESC_KEY 53
# define ZERO_KEY 82
# define KEY_1 83
# define KEY_3 85
# define KEY_5 87
# define KEY_2 84
# define ARROW_LEFT_KEY 123
# define ARROW_RIGHT_KEY 124
# define ARROW_DOWN_KEY 125
# define ARROW_UP_KEY 126
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_BUTTON 1
# define RIGHT_BUTTON 2
# define SHIFT_KOEF 30
# define SCROLL_DOWN_KOEF 1.15
# define SCROLL_UP_KOEF 0.85
# define SHIFT_ANGLE 2
# define U_CHAR (unsigned char)

int		my_fork(t_mlx *mlx, int argc, char **argv);

int		which_fractal(int fractal_number, t_mlx *mlx);

int		error_file(int status);

int		find_window_limits(t_mlx *mlx);
int		find_fractal_set(t_mlx *mlx);
void	set_tread_param(t_mlx *mlx, t_thread_data *thread_num);
void	*print_part_of_set(void *thread_data_void);
int		print_line(t_point imag, t_coord cur, t_mlx *mlx);

int		find_limit_mandelbrot(t_coord cur, t_mlx *mlx, t_coord *last_cur);
int		find_limit_julia(t_coord cur, t_mlx *mlx, t_coord *last_cur);
int		find_limit_ship(t_coord cur, t_mlx *mlx, t_coord *last_cur);
int		find_limit_celtic(t_coord cur, t_mlx *mlx, t_coord *last_cur);
int		find_limit_cube(t_coord cur, t_mlx *mlx, t_coord *last_cur);
int		find_limit_pretty(t_coord cur, t_mlx *mlx, t_coord *last_cur);

int		find_color(int limit, t_mlx *mlx, int color, t_coord *last_cur);
int		smooth_colors(int limit, t_mlx *mlx, int color, double idx);

int		parse_fractal(t_mlx *mlx);
int		init_mlx_param(t_mlx *mlx);

int		key_hook(int keycode, t_mlx *mlx);
int		shift_image(int keycode, t_mlx *mlx);
int		key_hook_tree(int keycode, t_mlx *mlx);
int		shift_tree(int keycode, t_mlx *mlx);
int		exit_x(t_mlx *mlx);

int		mouse_hook(int keycode, int x, int y, t_mlx *mlx);
int		mouse_scroll(int button, int x, int y, t_mlx *mlx);
int		julia_move(int x, int y, t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *mlx);
int		mouse_button_release(int button, int x, int y, t_mlx *mlx);

int		print_trees_fractal(t_mlx *mlx);
int		print_sierpinski_triangle(t_line line, int angle, t_mlx *mlx, int step);
int		print_pythagoras_tree(t_line line, int angle, t_mlx *mlx, int depth);

void	draw_square(t_line line, int angle, t_mlx *mlx);
t_line	change_param(t_line line, int angle, int *xy_swap, double a);
void	set_param(t_point *delta, int *error, t_point *dir, t_line line1);
void	draw_line(t_line line, int angle, t_mlx *mlx, int step);
int		check_dot(int x, int y);

#endif
