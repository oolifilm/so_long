/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:14:51 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/13 01:09:11 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->floor = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	load_image(t_data *data, char *path, void **img_ptr)
{
	*img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &(data->img.width),
			&(data->img.height));
	if (!*img_ptr)
	{
		ft_printf("Erreur: Impossible de charger l'image %s\n", path);
		exit(EXIT_FAILURE);
	}
}

void	set_img(t_data *data)
{
	data->img.height = 32;
	data->img.width = 32;
	data->img.floor = "./assets/0_floor.xpm";
	data->img.wall = "./assets/1_wall.xpm";
	data->img.collect = "./assets/C_collect.xpm";
	data->img.player = "./assets/P_player.xpm";
	data->img.exit = "./assets/E_exit.xpm";
	load_image(data, data->img.wall, &(data->img.img_wall));
	load_image(data, data->img.floor, &(data->img.img_floor));
	load_image(data, data->img.exit, &(data->img.img_exit));
	load_image(data, data->img.collect, &(data->img.img_collect));
	load_image(data, data->img.player, &(data->img.img_player));
}
