/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:26:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/20 15:26:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_square(t_line line, int angle, t_mlx *mlx)
{
	int			error;
	t_point		dir;
	t_point		delta;
	t_line		line_new;
	int			xy_swap;

	line_new = change_param(line, angle, &xy_swap, mlx->a);
	set_param(&delta, &error, &dir, line_new);
	while (line_new.x0 != line_new.x1)
	{
		line = (xy_swap) ?
			(t_line){line_new.y0, line_new.x0, line_new.y1, line_new.x1} :
			(t_line){line_new.x0, line_new.y0, line_new.x1, line_new.y1};
		draw_line(line, angle + 90, mlx, 0);
		error += delta.y;
		if (2 * error >= delta.x)
		{
			line_new.y0 += dir.y;
			error -= delta.x;
		}
		line_new.x0 += dir.x;
	}
}

t_line	change_param(t_line line, int angle, int *xy_swap, double a)
{
	t_line		line_new;

	line.x1 = line.x0 + (int)(a * cos(PI * angle));
	line.y1 = line.y0 - (int)(a * sin(PI * angle));
	if (ABS(line.y1 - line.y0) < abs(line.x1 - line.x0))
	{
		line_new = line;
		*xy_swap = 0;
	}
	else
	{
		line_new = (t_line){line.y0, line.x0, line.y1, line.x1};
		*xy_swap = 1;
	}
	return (line_new);
}

void	set_param(t_point *delta, int *error, t_point *dir, t_line line1)
{
	delta->x = ABS(line1.x1 - line1.x0);
	delta->y = ABS(line1.y1 - line1.y0);
	*error = 0;
	dir->y = (line1.y1 > line1.y0) ? 1 : -1;
	dir->x = (line1.x1 > line1.x0) ? 1 : -1;
}

void	draw_line(t_line line, int angle, t_mlx *mlx, int step)
{
	int			error;
	t_point		dir;
	t_point		delta;
	t_line		line1;
	int			xy_swap2;

	line1 = change_param(line, angle, &xy_swap2, mlx->a /
			((mlx->fractal_number == SIERPINSKI_TRIANGLE) ? pow(2, step) : 1));
	set_param(&delta, &error, &dir, line1);
	while (line1.x0 != line1.x1)
	{
		if (xy_swap2 && check_dot(line1.x0, line1.y0))
			mlx->img.data[line1.x0 * WIN_WIDTH + line1.y0] =
					find_color(mlx->max_iter - 1, mlx, mlx->color, NULL);
		else if (!xy_swap2 && check_dot(line1.x0, line1.y0))
			mlx->img.data[line1.y0 * WIN_WIDTH + line1.x0] =
					find_color(mlx->max_iter - 1, mlx, mlx->color, NULL);
		error += delta.y;
		if (2 * error >= delta.x)
		{
			line1.y0 += dir.y;
			error -= delta.x;
		}
		line1.x0 += dir.x;
	}
}

int		check_dot(int x, int y)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		return (1);
	else
		return (0);
}
