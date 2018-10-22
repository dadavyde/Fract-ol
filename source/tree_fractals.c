/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:11:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/12 18:11:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		print_trees_fractal(t_mlx *mlx)
{
	t_line	line;
	int		angle;
	int		x;

	x = 0;
	mlx->a = A_SIZE;
	angle = 0;
	line.x1 = mlx->tree_cord.x;
	line.y1 = mlx->tree_cord.y;
	while (++x < WIN_HEIGHT * WIN_WIDTH)
		mlx->img.data[x] = 0;
	if (mlx->fractal_number == PYTHAGORAS_TREE)
		print_pythagoras_tree(line, angle, mlx, mlx->depth);
	else
		print_sierpinski_triangle(line, angle + 90, mlx, 0);
	return (0);
}

int		print_sierpinski_triangle(t_line line, int angle, t_mlx *mlx, int step)
{
	int		idx;

	idx = 0;
	line.x0 = line.x1;
	line.y0 = line.y1;
	draw_line(line, angle, mlx, step);
	if (step == mlx->depth)
		return (0);
	else
	{
		line.x1 = line.x0 + (int)(mlx->a / pow(2, step) * cos(PI * (angle)));
		line.y1 = line.y0 - (int)(mlx->a / pow(2, step) * sin(PI * (angle)));
		while (idx < mlx->max_branch)
		{
			print_sierpinski_triangle(line, angle - mlx->tree_angle + 2 *
				mlx->tree_angle * idx / (mlx->max_branch - 1), mlx, step + 1);
			idx++;
		}
	}
	return (0);
}

int		print_pythagoras_tree(t_line line, int angle, t_mlx *mlx, int depth)
{
	line.x0 = line.x1;
	line.y0 = line.y1;
	if (depth <= mlx->depth - 1)
		mlx->a *= cos(PI * mlx->tree_angle);
	draw_square(line, angle, mlx);
	if (depth < 1)
		return (0);
	else
	{
		line.x1 = line.x0 + (int)(mlx->a * cos(PI * (angle + 90)));
		line.y1 = line.y0 - (int)(mlx->a * sin(PI * (angle + 90)));
		print_pythagoras_tree(line, angle + mlx->tree_angle, mlx, depth - 1);
		mlx->a /= pow(sin(PI * mlx->tree_angle), depth - 1);
		line.x1 = line.x1 + (int)(mlx->a * cos(PI * (angle + mlx->tree_angle)));
		line.y1 = line.y1 - (int)(mlx->a * sin(PI * (angle + mlx->tree_angle)));
		mlx->a /= (cos(PI * mlx->tree_angle) * cos(PI * mlx->tree_angle));
		mlx->a *= sin(PI * mlx->tree_angle);
		print_pythagoras_tree(line, angle + mlx->tree_angle - 90, mlx,
								depth - 1);
	}
	return (0);
}
