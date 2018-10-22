/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:07:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/09 20:07:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_color(int limit, t_mlx *mlx, int color, t_coord *last_cur)
{
	int		red;
	int		green;
	int		blue;

	if (limit == mlx->max_iter)
		return (0);
	else
	{
		if (color >= 4 && color <= 6)
			return (smooth_colors(limit, mlx, color, last_cur->imag +
					last_cur->real));
		else
		{
			red = (color == WHITE || color == RED) ? (1 << 16) : 0;
			green = (color == WHITE || color == GREEN) ? (1 << 8) : 0;
			blue = (color == WHITE || color == BLUE) ? 1 : 0;
			return (0xff * limit / mlx->max_iter * (red + green + blue));
		}
	}
}

int		smooth_colors(int limit, t_mlx *mlx, int color, double idx)
{
	int		red;
	int		green;
	int		blue;

	idx = limit + 1 - (log(2) / sqrt(idx)) / log(2);
	if (color == 4)
	{
		red = U_CHAR(sin(0.016 * idx + limit % 4) * 230 + 25);
		green = U_CHAR(sin(0.013 * idx + limit % 4) * 230 + 25);
		blue = U_CHAR(sin(0.01 * idx + limit % 4) * 230 + 25);
	}
	else if (color == 5)
	{
		red = U_CHAR(sin(0.056 * idx + mlx->max_iter % 4) * 125 + 125);
		green = U_CHAR(sin(0.07 * idx + mlx->max_iter % 3) * 125 + 125);
		blue = U_CHAR(sin(0.01 * idx + mlx->max_iter % 5) * 125 + 125);
	}
	else
	{
		red = U_CHAR(sin(0.026 * idx * 2 + 0) * 125 + 125);
		green = U_CHAR(sin(0.021 * idx * 2 + 0) * 125 + 125);
		blue = U_CHAR(sin(0.02 * idx * 2 + 0) * 125 + 125);
	}
	return (red * (1 << 16) + green * (1 << 8) + blue);
}
