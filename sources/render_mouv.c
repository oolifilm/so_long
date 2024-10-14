/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:34:30 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/11 23:38:31 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Félicitations, vous avez gagné en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Félicitations, vous avez gagné en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Félicitations, vous avez gagné en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.floor;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				ft_printf("Félicitations, vous avez gagné en : %d coup !\n",
					data->count);
				end(data);
			}
		}
	}
}
