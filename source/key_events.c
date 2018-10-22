/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:16:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/14 20:16:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == ASTERISK_KEY)
		mlx->color = (mlx->color + 1) % 7;
	else if (keycode == MINUS_KEY)
		mlx->max_iter--;
	else if (keycode == PLUS_KEY)
		mlx->max_iter++;
	else if (keycode == ARROW_LEFT_KEY || keycode == ARROW_RIGHT_KEY ||
			keycode == ARROW_DOWN_KEY || keycode == ARROW_UP_KEY)
		shift_image(keycode, mlx);
	else if (keycode == ZERO_KEY)
		find_window_limits(mlx);
	find_fractal_set(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int		shift_image(int keycode, t_mlx *mlx)
{
	if (keycode == ARROW_LEFT_KEY && mlx->tree_angle < 90)
		mlx->window_min.real -= SHIFT_KOEF * mlx->step.real;
	else if (keycode == ARROW_RIGHT_KEY && mlx->tree_angle > 1)
		mlx->window_min.real += SHIFT_KOEF * mlx->step.real;
	else if (keycode == ARROW_UP_KEY)
		mlx->window_min.imag -= SHIFT_KOEF * mlx->step.imag;
	else
		mlx->window_min.imag += SHIFT_KOEF * mlx->step.imag;
	mlx->window_max.real = mlx->window_min.real + WIN_WIDTH * mlx->step.real;
	mlx->window_max.imag = mlx->window_min.imag + WIN_HEIGHT * mlx->step.imag;
	return (0);
}

int		key_hook_tree(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		exit_x(mlx);
	else if (keycode == ASTERISK_KEY)
		mlx->color = (mlx->color + 1) % 4;
	else if (keycode == ZERO_KEY)
		mlx->tree_angle = 44;
	else if (keycode == MINUS_KEY && mlx->depth)
		mlx->depth--;
	else if (keycode == PLUS_KEY && mlx->depth < 10)
		mlx->depth++;
	else if (keycode == KEY_1 && mlx->tree_angle <= 180)
		mlx->tree_angle += SHIFT_ANGLE;
	else if (keycode == KEY_3 && mlx->tree_angle >= 0)
		mlx->tree_angle -= SHIFT_ANGLE;
	else if (keycode == KEY_5 && mlx->max_branch < 90)
		mlx->max_branch++;
	else if (keycode == KEY_2 && mlx->max_branch > 2)
		mlx->max_branch--;
	else if (keycode >= ARROW_LEFT_KEY && keycode <= ARROW_UP_KEY)
		shift_tree(keycode, mlx);
	print_trees_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int		shift_tree(int keycode, t_mlx *mlx)
{
	if (keycode == ARROW_LEFT_KEY)
		mlx->tree_cord.x++;
	else if (keycode == ARROW_RIGHT_KEY)
		mlx->tree_cord.x--;
	else if (keycode == ARROW_UP_KEY)
		mlx->tree_cord.y++;
	else
		mlx->tree_cord.y--;
	return (0);
}

int		exit_x(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}
