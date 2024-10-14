/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:42:52 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/13 00:30:58 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_line(char *str, char **map_copy, int i, t_data *data)
{
	int	j;

	map_copy[i] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!map_copy[i])
		ft_error("Error: MALLOC\n", data);
	j = 0;
	while (str[j] != '\0')
	{
		map_copy[i][j] = str[j];
		j++;
	}
	map_copy[i][j] = '\0';
}

char	**clone_map(t_data *data)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (data->height + 1));
	if (!map_copy)
	{
		ft_error("Error: MALLOC for clone\n", data);
		return (NULL);
	}
	while (i < data->height)
	{
		copy_line(data->map[i], map_copy, i, data);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	flood_fill_collectable(char **map_copy, t_pos pos, t_data *data)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= data->height || x >= (int)ft_strlen(map_copy[0]))
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V' || map_copy[y][x] == 'E')
		return ;
	map_copy[y][x] = 'V';
	flood_fill_collectable(map_copy, (t_pos){x, y + 1}, data);
	flood_fill_collectable(map_copy, (t_pos){x, y - 1}, data);
	flood_fill_collectable(map_copy, (t_pos){x + 1, y}, data);
	flood_fill_collectable(map_copy, (t_pos){x - 1, y}, data);
}

void	flood_fill_exit(char **map_copy, t_pos pos, t_data *data)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x < 0 || y < 0 || y >= data->height || x >= (int)ft_strlen(map_copy[0]))
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V' || map_copy[y][x] == 'C')
		return ;
	map_copy[y][x] = 'V';
	flood_fill_exit(map_copy, (t_pos){x, y + 1}, data);
	flood_fill_exit(map_copy, (t_pos){x, y - 1}, data);
	flood_fill_exit(map_copy, (t_pos){x + 1, y}, data);
	flood_fill_exit(map_copy, (t_pos){x - 1, y}, data);
}

void	ft_duplicate(t_data *data)
{
	check_collectables(data);
	check_exit(data);
}
