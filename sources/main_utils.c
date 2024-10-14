/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:29:17 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/13 00:39:02 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_data *data)
{
	data->img.img_player = NULL;
	data->img.img_exit = NULL;
	data->img.img_wall = NULL;
	data->img.img_collect = NULL;
	data->img.img_floor = NULL;
	data->mlx_win = NULL;
	data->mlx_ptr = NULL;
	data->map = NULL;
}

void	free_mlx(t_data *data)
{
	if (data->mlx_ptr != NULL)
	{
		if (data->img.img_wall)
			mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		if (data->img.img_floor)
			mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		if (data->img.img_collect)
			mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		if (data->img.img_player)
			mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		if (data->img.img_exit)
			mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
