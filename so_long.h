/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:14:53 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:19:53 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64

//#include "minilibx-linux/mlx.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*one_line(char *string);
char	*read_buff(int fd, char *buff, char *string);
char	*remaining_data(char *string);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mc;
	int		h;
	int		w;
	int		cc;
	int		cnt;
	int		ey;
	int		ex;
	int		px;
	int		py;
}	t_game;

typedef struct s_image
{
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*nothing;
	int		h;
	int		w;
}	t_img;

typedef struct s_all
{
	t_game	*g;
	t_img	*i;
}	t_all;

void	puterror(char *msg);
void	clean_2d_arr(char **arr);
char	**read_map(char	*file, t_game *p);
void	initialize_utils(t_game *utils, char **av);
int		check_lines_len(char **map, size_t len);
void	error_handling(char *msg, char **map, t_game *game);
void	map_parsing(t_game *g_ptr, char **av);
int		it_has_char(char c, t_game *p);
int		check_valid_chars(t_game *p);
int		it_has_char(char c, t_game *p);
int		check_file_extension(char *file);
int		validate_game_utils(char **map);
int		check_height_width(t_game *game);
void	initialize_game(t_game	*game);
t_img	*allocate_sprites(t_game *game);
void	draw_sprites(t_game *game, t_img *img);
void	put_image(t_game *game, t_img *img, int x, int y);
char	**copy_map(t_game *game);
void	ft_free_up(t_game *g, t_img *i);
t_all	*create_container(t_game *ga, t_img *im);
void	ft_clean_container(t_all *a);
void	open_window(t_game *game);
void	move_right(t_all *p, int *c);
void	move_left(t_all *p, int *c);
void	move_up(t_all *p, int *c);
void	move_down(t_all *p, int *c);
int		event_handling(int keycode, t_all *a);
void	ft_error_case(t_all *a, char *msg);
void	ft_putnbr(int n);
int		cnt_collectibles(t_game *g);
void	check_collectible_nbr(t_all *p);
void	character_pos(t_all *a, int *yp, int *xp, char c);
void	up_process(t_all *p, int *c, int y, int x);
void	down_process(t_all *p, int *c, int y, int x);
void	right_process(t_all *p, int *c, int y, int x);
void	left_process(t_all *p, int *c, int y, int x);
void	ft_flood_fill(char **map, int x, int y);
void	player_pos(t_game *g, int *yp, int *xp);
int		check_if_playable(char **map);
void	helper(char **map, int *a, int x, int y);
int		check_chars_existence(char **map);
size_t	len_line(char *s);
int		sub_wall(char *s);
void	fill_arr(char **map, int *a, int i, int j);
void	initial_clear(t_game *g);
void	ft_destroy_game(t_game *g, t_img *i, char flag);
void	ft_cleaner0(t_game *g, t_img*i, char *msg);
void	ft_cleaner1(t_game *g, t_img*i, char *msg);
void	ft_cleaner2(t_game *g, t_img*i, char *msg);
void	ft_cleaner3(t_game *g, t_img*i, char *msg);
void	ft_cleaner4(t_game *g, t_img*i, char *msg);
#endif
