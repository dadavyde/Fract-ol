/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/17 18:42:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		error_file(int status)
{
	if (status == BAD_FILE)
		ft_putendl("Invalid file");
	if (status == WRONG_NUMBER_OF_FILES || status == BAD_FILE)
	{
		ft_putendl("\nusage: ./fractol X (fractal number)\n");
		ft_putendl("        Mandelbrot - 1");
		ft_putendl("        Julia - 2");
		ft_putendl("        Burning_ship - 3");
		ft_putendl("        Celtic_mandelbrot  - 4");
		ft_putendl("        Cube_mandelbrot - 5");
		ft_putendl("        Pythagoras_tree - 6");
		ft_putendl("        Sierpinski_triangle- 7");
		ft_putendl("        PRETTY_FRACTAL - 8");
		ft_putendl("        for shift use mouse arrays");
		ft_putendl("        to zoom in/out use mouse wheel");
		ft_putendl("        for change tree angle use keys \"1\" and \"3\"");
		ft_putendl("        for change depth use keys \"-\" and \"+\"");
		ft_putendl("        to return to the original position of the fractal"
							"use \"0\"");
	}
	return (0);
}
