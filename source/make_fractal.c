/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:20:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/17 18:20:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_window_limits(t_mlx *mlx)
{
	if (mlx->fractal_number == MANDELBROT || mlx->fractal_number == BURNING_SHIP
		|| mlx->fractal_number == CELTIC_MANDELBROT)
	{
		mlx->window_min = (t_coord){-1.5, -2.0};
		mlx->window_max.real = 1.0;
	}
	else if (mlx->fractal_number == JULIA || mlx->fractal_number ==
			CUBE_MANDELBROT || mlx->fractal_number == PRETTY_FRACTAL)
	{
		mlx->window_min = (t_coord){-2.0, -2.0};
		mlx->window_max.real = 2.0;
	}
	mlx->window_max.imag = mlx->window_min.imag + (mlx->window_max.real -
						mlx->window_min.real) / WIN_WIDTH * WIN_HEIGHT;
	mlx->step.real = (mlx->window_max.real - mlx->window_min.real) / WIN_WIDTH;
	mlx->step.imag = (mlx->window_max.imag - mlx->window_min.imag) / WIN_HEIGHT;
	return (0);
}

int		find_fractal_set(t_mlx *mlx)
{
	pthread_t		threads[THREAD_MAX - 1];
	t_thread_data	thread_num[THREAD_MAX];
	int				idx;

	set_tread_param(mlx, thread_num);
	idx = 0;
	while (idx < THREAD_MAX - 1)
	{
		pthread_create(&threads[idx], NULL, print_part_of_set,
						(thread_num + idx));
		idx++;
	}
	print_part_of_set((thread_num + THREAD_MAX - 1));
	idx = 0;
	while (idx < THREAD_MAX - 1)
		pthread_join(threads[idx++], NULL);
	return (0);
}

void	set_tread_param(t_mlx *mlx, t_thread_data *thread_num)
{
	int		idx;

	idx = 0;
	while (idx < THREAD_MAX)
	{
		thread_num[idx].mlx = mlx;
		thread_num[idx].first_imag_x = idx;
		idx++;
	}
}

void	*print_part_of_set(void *thread_data_void)
{
	t_point			imag;
	t_coord			cur;
	t_thread_data	*thread_data;
	t_mlx			*mlx;

	thread_data = (t_thread_data*)thread_data_void;
	mlx = thread_data->mlx;
	imag.y = 0;
	cur.imag = mlx->window_min.imag;
	imag.x = thread_data->first_imag_x;
	cur.real = mlx->window_min.real + imag.x * mlx->step.real;
	while (imag.y < WIN_HEIGHT)
	{
		print_line(imag, cur, mlx);
		imag.y++;
		cur.imag += mlx->step.imag;
	}
	return (0);
}

int		print_line(t_point imag, t_coord cur, t_mlx *mlx)
{
	int		first_pixel_num;
	double	step_real;
	int		color;
	t_coord	last_cur;

	first_pixel_num = imag.y * WIN_WIDTH;
	step_real = THREAD_MAX * mlx->step.real;
	while (imag.x < WIN_WIDTH)
	{
		color = find_color(mlx->find_limit(cur, mlx, &last_cur),
							mlx, mlx->color, &last_cur);
		mlx->img.data[first_pixel_num + imag.x] = color;
		imag.x += THREAD_MAX;
		cur.real += step_real;
	}
	return (0);
}
