/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:36:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/16 20:36:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		which_fractal(int fractal_number, t_mlx *mlx)
{
	mlx->fractal_number = fractal_number;
	if (fractal_number >= MANDELBROT && fractal_number <= SIERPINSKI_TRIANGLE)
	{
		if (fractal_number == MANDELBROT)
			mlx->find_limit = find_limit_mandelbrot;
		else if (fractal_number == JULIA)
			mlx->find_limit = find_limit_julia;
		else if (fractal_number == BURNING_SHIP)
			mlx->find_limit = find_limit_ship;
		else if (fractal_number == CELTIC_MANDELBROT)
			mlx->find_limit = find_limit_celtic;
		else if (fractal_number == CUBE_MANDELBROT)
			mlx->find_limit = find_limit_cube;
		else if (fractal_number == PRETTY_FRACTAL)
			mlx->find_limit = find_limit_pretty;
		return (TRUE);
	}
	else
		return (FALSE);
}
