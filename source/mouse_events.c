/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:20:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/03/14 20:20:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_scroll(button, x, y, mlx);
	else if (button == LEFT_BUTTON)
	{
		mlx->press_button = TRUE;
		mlx->last_coord = (t_point){x, y};
	}
	else if (button == RIGHT_BUTTON)
		mlx->unlock_julia = (mlx->unlock_julia) ? FALSE : TRUE;
	find_fractal_set(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int		mouse_scroll(int button, int x, int y, t_mlx *mlx)
{
	double		zoom_koef;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			zoom_koef = SCROLL_UP_KOEF;
		else
			zoom_koef = SCROLL_DOWN_KOEF;
		mlx->window_min.real = mlx->window_min.real + x *
								(1 - zoom_koef) * mlx->step.real;
		mlx->step.real *= zoom_koef;
		mlx->window_max.real = mlx->window_min.real + WIN_WIDTH *
								mlx->step.real;
		mlx->window_min.imag = mlx->window_min.imag +
								y * (1 - zoom_koef) * mlx->step.imag;
		mlx->step.imag *= zoom_koef;
		mlx->window_max.imag = mlx->window_min.imag + WIN_HEIGHT *
								mlx->step.imag;
	}
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->press_button)
	{
		mlx->window_min.real -= mlx->step.real * (x - mlx->last_coord.x);
		mlx->window_max.real -= mlx->step.real * (x - mlx->last_coord.x);
		mlx->window_min.imag -= mlx->step.real * (y - mlx->last_coord.y);
		mlx->window_max.imag -= mlx->step.real * (y - mlx->last_coord.y);
		mlx->last_coord.x = x;
		mlx->last_coord.y = y;
		find_fractal_set(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	}
	else if (mlx->unlock_julia)
		julia_move(x, y, mlx);
	return (0);
}

int		julia_move(int x, int y, t_mlx *mlx)
{
	mlx->julia_coord.imag = (2 * y - WIN_HEIGHT) / (float)WIN_HEIGHT;
	mlx->julia_coord.real = (2 * x - WIN_WIDTH) / (float)WIN_WIDTH;
	find_fractal_set(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int		mouse_button_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == LEFT_BUTTON && mlx->press_button)
		mlx->press_button = FALSE;
	return (0);
}
