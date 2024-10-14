/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:07:13 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/14 12:52:18 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(int fd, t_data *data)
{
	char	*line_map;
	char	*buff;
	char	*tmp_buff;

	line_map = get_next_line(fd);
	buff = ft_strdup("");
	if (line_map)
	{
		tmp_buff = buff;
		while (line_map)
		{
			tmp_buff = buff;
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = get_next_line(fd);
		}
		return (buff);
	}
	if (buff != NULL)
		free(buff);
	close(fd);
	ft_error("Error\nWrong lecture map\n", data);
	return (NULL);
}

void	*ft_free_map(t_data *data)
{
	int	i;

	if (data == NULL)
		return (0);
	if (data->map == NULL)
		return (0);
	i = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i] != NULL)
			free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

int	check_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	if (!ft_check_line(map[0], data->content.wall, data))
		return (0);
	while (map[i])
	{
		if (!ft_check_col(map[i], data->content.wall, data)
			|| !ft_check_other(map[i], &(data->content), data))
			return (0);
		i++;
	}
	if (!ft_check_line(map[i - 1], data->content.wall, data))
		return (0);
	data->height = i;
	return (1);
}

char	**parse_map(int fd, t_data *data)
{
	char	*map_string;

	map_string = get_map(fd, data);
	if (!map_string)
		return (NULL);
	data->map = ft_split(map_string, '\n');
	if (!data->map)
		return (0);
	free(map_string);
	ft_check_content(data);
	if (!ft_check_format(data->map, data) || !check_map(data->map, data))
		return (ft_free_map(data));
	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchar(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map founded\n", data));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (close(fd), ft_error("Error\nFailed to open file\n", data));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			close(fd);
			ft_free_map(data);
			return (ft_error("Error\nNeed 1 Player/Exit and at least 1 Object\n",
					data));
		}
		close(fd);
	}
	return (data->map);
}
