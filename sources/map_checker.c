/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:55:29 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/11 23:42:21 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_col(char *map_line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Error\nMap column not close\n", data);
		return (0);
	}
	data->width = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_error("Error\nMap line not close\n", data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cnt *content, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_error("Error\nWrong number of player or exit\n", data);
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->floor)
		{
			ft_error("Error\nUnknown symbol(s) in map\n", data);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[i][y] == data->content.player)
			{
				data->content.count_p += 1;
				data->pos.x = y;
				data->pos.y = i;
			}
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	ft_check_format(char **map, t_data *data)
{
	int	y;
	int	i;
	int	count_i;

	i = 0;
	y = 0;
	count_i = 0;
	while (map[0][count_i])
		count_i++;
	while (map[y] != NULL)
	{
		while (map[y][i])
			i++;
		if (i != count_i)
		{
			ft_error("Error\nMap must be a rectangle or a square\n", data);
			return (0);
		}
		i = 0;
		y++;
	}
	return (1);
}
