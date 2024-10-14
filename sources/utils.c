/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:23:51 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/13 01:11:13 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strchar(char *str, char *cmp)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}

int	ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_error(char *str, t_data *data)
{
	write(2, str, ft_strlen(str));
	ft_free_map(data);
	end(data);
	exit(EXIT_FAILURE);
}

void	check_collectables(t_data *data)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = clone_map(data);
	if (!map_copy)
		ft_error("Error: Copied Map!\n", data);
	flood_fill_collectable(map_copy, (t_pos){data->pos.x, data->pos.y}, data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C')
			{
				ft_free_map(&(t_data){.map = map_copy});
				ft_error("Flood Fill! Collectable not reachable!\n", data);
			}
			j++;
		}
		i++;
	}
	ft_free_map(&(t_data){.map = map_copy});
}

void	check_exit(t_data *data)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = clone_map(data);
	if (!map_copy)
		ft_error("Error: Copied Map!\n", data);
	flood_fill_exit(map_copy, (t_pos){data->pos.x, data->pos.y}, data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E')
			{
				ft_free_map(&(t_data){.map = map_copy});
				ft_error("Flood Fill! Exit not reachable!\n", data);
			}
			j++;
		}
		i++;
	}
	ft_free_map(&(t_data){.map = map_copy});
}
