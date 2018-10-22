/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:21:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/17 18:21:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_coord
{
	double			imag;
	double			real;
}					t_coord;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				b_per_p;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_line;

struct s_mlx;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_img			img;
	int				(*find_limit)(t_coord, struct s_mlx*, t_coord*);
	int				fractal_number;
	t_coord			window_max;
	t_coord			window_min;
	t_coord			step;
	int				color;
	int				max_iter;
	int				press_button;
	t_point			last_coord;
	t_coord			julia_coord;
	int				unlock_julia;
	int				depth;
	int				tree_angle;
	double			a;
	t_point			tree_cord;
	int				max_branch;
}					t_mlx;

typedef struct		s_thread_data
{
	t_mlx			*mlx;
	int				first_imag_x;
}					t_thread_data;

#endif
