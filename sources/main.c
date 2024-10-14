/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:38:40 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/14 12:39:10 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	chk_collect(t_data *data)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

int	end(t_data *data)
{
	free_map(data);
	free_mlx(data);
	exit(0);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
		render_top(data);
	if (keysym == XK_d)
		render_right(data);
	if (keysym == XK_a)
		render_left(data);
	if (keysym == XK_s)
		render_down(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_data(&data);
	if (!envp[0] || argc != 2)
		return (ft_error("Error\nThis program takes 1 argument .ber\n", &data),
			0);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	set_content(&(data.content));
	data.map = map_core(argv, &data);
	if (data.map != NULL)
	{
		ft_duplicate(&data);
		set_img(&data);
		core_render(&data);
	}
	else
		end(&data);
	return (1);
}
