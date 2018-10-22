/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:24:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/24 16:24:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		parse_fractal(t_mlx *mlx)
{
	init_mlx_param(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	if (mlx->fractal_number >= MANDELBROT &&
		mlx->fractal_number <= PRETTY_FRACTAL)
		mlx_hook(mlx->win, 2, 5, key_hook, mlx);
	else
		mlx_hook(mlx->win, 2, 5, key_hook_tree, mlx);
	mlx_hook(mlx->win, 4, 5, mouse_hook, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, mouse_button_release, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, exit_x, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int		init_mlx_param(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, W_TITLE);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
				&(mlx->img.b_per_p), &(mlx->img.size_line), &(mlx->img.endian));
	mlx->depth = 2;
	mlx->tree_angle = 45;
	mlx->max_branch = 3;
	mlx->tree_cord = (t_point){TREE_X, TREE_Y};
	mlx->max_iter = 40;
	if (mlx->fractal_number >= MANDELBROT &&
		mlx->fractal_number <= PRETTY_FRACTAL)
	{
		find_window_limits(mlx);
		find_fractal_set(mlx);
	}
	else
		print_trees_fractal(mlx);
	return (0);
}
