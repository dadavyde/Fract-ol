/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_iter_main_fractal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:01:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/21 20:01:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_limit_mandelbrot(t_coord cur, t_mlx *mlx, t_coord *last_cur)
{
	t_coord		tmp;
	t_coord		tmp_squared;
	int			iteration;

	tmp = (t_coord){cur.imag, cur.real};
	iteration = 0;
	while (iteration < mlx->max_iter)
	{
		tmp_squared = (t_coord){tmp.imag * tmp.imag, tmp.real * tmp.real};
		if (tmp_squared.real + tmp_squared.imag > 4)
			break ;
		tmp.imag = 2 * tmp.real * tmp.imag + cur.imag;
		tmp.real = tmp_squared.real - tmp_squared.imag + cur.real;
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}

int		find_limit_julia(t_coord cur, t_mlx *mlx, t_coord *last_cur)
{
	t_coord		tmp;
	t_coord		tmp_squared;
	int			iteration;

	tmp = (t_coord){cur.imag, cur.real};
	iteration = 0;
	while (iteration < mlx->max_iter)
	{
		tmp_squared = (t_coord){tmp.imag * tmp.imag, tmp.real * tmp.real};
		if (tmp_squared.real + tmp_squared.imag > 4)
			break ;
		tmp.imag = 2 * tmp.real * tmp.imag + mlx->julia_coord.imag;
		tmp.real = tmp_squared.real - tmp_squared.imag + mlx->julia_coord.real;
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}
