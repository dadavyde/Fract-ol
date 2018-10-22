/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:19:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/02/17 18:19:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	ft_bzero((void*)&mlx, sizeof(t_mlx));
	if (argc < 2)
		return (error_file(WRONG_NUMBER_OF_FILES));
	else if (argc > 1)
		my_fork(&mlx, argc, argv);
	return (0);
}

int		my_fork(t_mlx *mlx, int argc, char **argv)
{
	int		idx;

	idx = 1;
	while (idx < argc)
	{
		if (fork() == 0)
		{
			if (!which_fractal(ft_atoi(argv[idx]), mlx))
				return (error_file(BAD_FILE));
			parse_fractal(mlx);
		}
		idx++;
	}
	wait(NULL);
	return (0);
}
