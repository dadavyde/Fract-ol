/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_iter_bonus_fractal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:41:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/20 15:41:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_limit_ship(t_coord cur, t_mlx *mlx, t_coord *last_cur)
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
		tmp.imag = 2 * ABS(tmp.real) * ABS(tmp.imag) + cur.imag;
		tmp.real = tmp_squared.real - tmp_squared.imag + cur.real;
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}

int		find_limit_celtic(t_coord cur, t_mlx *mlx, t_coord *last_cur)
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
		tmp.imag = 2.5 * tmp.real * tmp.imag + 0.01 * cur.imag;
		tmp.real = tmp_squared.real - 1.3 * tmp_squared.imag + 0.65 * cur.real;
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}

int		find_limit_cube(t_coord cur, t_mlx *mlx, t_coord *last_cur)
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
		tmp.imag = tmp.imag * (3 * tmp_squared.real - tmp_squared.imag) +
				cur.imag;
		tmp.real = tmp.real * (tmp_squared.real - 3 * tmp_squared.imag) +
				cur.real;
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}

int		find_limit_pretty(t_coord cur, t_mlx *mlx, t_coord *last_cur)
{
	t_coord		tmp_prev;
	t_coord		tmp;
	t_coord		tmp_next;
	t_coord		tmp_squared;
	int			iteration;

	tmp_prev = (t_coord){0, 0};
	tmp = (t_coord){cur.imag, cur.real};
	iteration = 0;
	while (iteration < mlx->max_iter)
	{
		tmp_squared = (t_coord){tmp.imag * tmp.imag, tmp.real * tmp.real};
		if (tmp_squared.real + tmp_squared.imag > 4)
			break ;
		tmp_next.real = tmp_squared.real - tmp_squared.imag +
				0.56667 - 0.5 * tmp_prev.real;
		tmp_next.imag = tmp.real * tmp.imag * 2 + (-0.5 * tmp_prev.imag);
		tmp_prev = (t_coord){tmp.imag, tmp.real};
		tmp = (t_coord){tmp_next.imag, tmp_next.real};
		iteration++;
	}
	*last_cur = (t_coord){tmp_squared.imag, tmp_squared.real};
	return (iteration);
}
