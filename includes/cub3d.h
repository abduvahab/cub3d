/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:02:13 by areheman          #+#    #+#             */
/*   Updated: 2022/12/02 17:01:05 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define RH 		124
# define LF 		123
# define UP 		126
# define DW 		125
# define W			13
# define A			0
# define S			1
# define D			2
# define ESC		53
# define UNIT		64
# define S_WIDTH 	900
# define S_HEIGHT 	720

typedef struct s_pos{
	double		x;
	double		y;

}			t_pos;

typedef struct s_vector{
	double		x;
	double		y;

}			t_vector;

typedef struct s_player{
	t_pos		pos;
	t_vector	dir;
	t_vector	plan;
	int			mapx;
	int			mapy;
	double		m_speed;
	double		r_speed;
}			t_player;

typedef struct s_cast{
	t_vector	ray_dir;
	t_pos		side_dis;
	t_pos		delta_dis;
	double		camera;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			mapx;
	int			mapy;
	int			side;
}			t_cast;

typedef struct s_text{
	void		*img;
	double		wallx;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			*add;
	int			t_w;
	int			t_h;
	int			num;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	char		*name;
}			t_text;

typedef struct s_screen
{
	void		*img;
	char		*add;
	double		lineheight;
	int			start;
	int			end;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
}			t_screen;

typedef struct s_map
{
	char		**map_char;
	char		player_start_dir_char;
	int			player_start_pos_x;
	int			player_start_pos_y;
	int			lines;
	int			cols;
	int			check_n;
	int			check_s;
	int			check_e;
	int			check_w;
	int			check_c;
	int			check_f;
	int			read_map;
}			t_map;

typedef struct s_minimap
{
	void		*mini_img;
	void		*pl_img;
	char		*mini_add;
	char		*pl_add;
	t_pos		player;
	int			w_mini;
	int			h_mini;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
	int			unt;
}				t_minimap;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			**map_int;
	char		*map_path;
	char		*input_str;
	int			r_ceil;
	int			g_ceil;
	int			b_ceil;
	int			r_floor;
	int			g_floor;
	int			b_floor;
	int			color_floor;
	int			color_sky;
	int			one_player;
	int			fd;
	t_minimap	mini;
	t_map		map;
	t_text		text[4];
	t_screen	scr;
	t_cast		ray;
	t_player	player;
}			t_data;

//cub3d.c
int		my_close(t_data *p);

void	ft_player_conf(t_data *data);

//casting.c
void	ray_casting(t_data *data);

//key_hook.c
int		key_hook(int k, t_data *data);

//key_hook_details.c
void	key_up_dw(int k, t_data *data);
void	key_d(int k, t_data *data);
void	key_a(int k, t_data *data);
void	key_rh(t_data *data);
void	key_lf(t_data *data);

//configure.c
void	ft_player_conf(t_data *data);
void	text_conf(t_data *data);

//draw_and_text.c
void	my_pixel_put(t_data *data, int x, int y, int color);
void	draw_screen(t_data *data, int x);
void	get_num_texture(t_data *data);
void	set_texture(t_data *data);
void	find_start_end_point(t_data *data);
void	my_pixel_put_screen(t_data *data, int y, int j);

//ctrl_map 
int		ctrl_map(t_data *data);
int		ctrl_map_char(t_data *data);
int		ctrl_map_space(t_data *data);
int		ctrl_blank(char c);
int		ctrl_one_player(t_data *data);

//ctrl_map_border
int		ctrl_map_border(t_data *data);
int		ctrl_map_top(t_data *data);
int		ctrl_map_bottom(t_data *data);
int		ctrl_map_left(t_data *data);
int		ctrl_map_right(t_data *data);

//file_check.c
void	ctrl_file(int argc, char **argv, t_data *data);
void	init_data_map(t_data *data);

//parsing_map.c
void	pars_all(t_data *data);
int		pars_open_map(t_data *data);
void	get_map_size(t_data *data);
void	ctrl_emtpy_map(t_data *data);
int		ctrl_empty_line(char *line);

//parsing_deco.c
void	pars_deco(char *path, t_data *data);
int		get_path_text(char *path, int index, t_data *data);
int		get_color_ceil(char *path, t_data *data);
int		get_color_floor(char *path, t_data *data);

//parsing_map_utils
int		ctrl_flag(t_data *data);
int		test_char(char c, char *str);
int		test_tab_int(int *tab, t_map map);
int		ctrl_color(int r, int g, int b);

//parsing_tab_int.c 
void	get_tab_int(t_data *data);
void	init_tab_int(t_data *data);
void	fill_tab_int(t_data *data, int i, int j);
void	set_player(t_data *data, int i, int j);

//utils.c
void	error_print(char *str);
int		last_line_pos(t_data *data);
int		char_count(char *str, char c);

//get_next_line + utils
char	*get_next_line(int fd);
char	*get_line(char *s);
char	*ft_save(char *s);
char	*ft_read_save(char *save, int fd);

// mini_map.c
void	set_mini_map_player(t_data *data);
void	draw_mini_map_player(t_data *data);

#endif