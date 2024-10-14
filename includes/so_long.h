/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:15:25 by leaugust          #+#    #+#             */
/*   Updated: 2024/10/13 02:13:38 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}			t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	floor;
	int		count_p;
	int		count_e;
	int		count_c;
}			t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}			t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	t_pos	exit;
	int		count;
}			t_data;

void		destroy_images(t_data *data);
void		destroy_window(t_data *data);
void		init_data(t_data *data);
void		free_mlx(t_data *data);
void		free_end(t_data *data);
void		init_data(t_data *data);
int			ft_check_col(char *map_line, char wall, t_data *data);
int			ft_check_line(char *map_line, char wall, t_data *data);
int			ft_check_other(char *map_line, t_cnt *content, t_data *data);
void		ft_check_content(t_data *data);
int			ft_check_format(char **map, t_data *data);
void		load_image(t_data *data, char *path, void **img_ptr);
void		copy_line(char *str, char **map_copy, int i, t_data *data);
char		**clone_map(t_data *data);
void		flood_fill_collectable(char **map_copy, t_pos pos, t_data *data);
void		flood_fill_exit(char **map_copy, t_pos pos, t_data *data);
void		check_exit(t_data *data);
void		check_collectables(t_data *data);
void		ft_duplicate(t_data *data);
void		print_map(char **map, int height);
char		*get_map(int fd, t_data *data);
void		*ft_free_map(t_data *data);
char		**parse_map(int fd, t_data *data);
int			check_map(char **map, t_data *data);
char		**map_core(char **str, t_data *data);
void		render_top(t_data *data);
void		render_right(t_data *data);
void		render_left(t_data *data);
void		render_down(t_data *data);
void		render_background(t_data *data);
void		render_other(t_data *data);
int			render(t_data *data);
void		core_render(t_data *data);
void		print_img(t_data *data, void *img, int x, int y);
void		set_content(t_cnt *content);
void		set_img(t_data *data);
int			chk_collect(t_data *data);
int			end(t_data *data);
int			key_press(int keysym, t_data *data);
int			main(int argc, char **argv, char **envp);
int			ft_same_char(char *str);
void		*ft_error(char *str, t_data *data);
int			ft_strchar(char *str, char *cmp);

#endif