/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:51:19 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:57:14 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines_len(char **map, size_t len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (len != len_line(map[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_walls(t_game *p)
{
	int	i;

	if (sub_wall(p->map[0]) != 0 || sub_wall(p->map[p->h - 1]) != 0)
		return (-1);
	i = 0 ;
	while (p->map[i] && p->map[i][0] != '\n')
	{
		if (p->map[i][0] != '1' || p->map[i][p->w - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_valid_chars(t_game *p)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (j <= p-> w - 2)
		{
			c = p->map[i][j];
			if (it_has_char(c, p) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error_handling(char *msg, char **map, t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clean_2d_arr(map);
	clean_2d_arr(game->mc);
	free(game);
	puterror(msg);
}

void	map_parsing(t_game *g_ptr, char **av)
{
	if (check_lines_len(g_ptr->map, g_ptr->w) != 0)
		error_handling("Error:\ninvalid map", g_ptr->map, g_ptr);
	if (check_chars_existence(g_ptr->map) != 0)
		error_handling("Error:\ninvalid characters", g_ptr->map, g_ptr);
	if (check_walls(g_ptr) != 0)
		error_handling("Error:\ninvalid map", g_ptr->map, g_ptr);
	if (check_valid_chars(g_ptr) != 0)
		error_handling("Error:\ninvalid characters", g_ptr->map, g_ptr);
	if (check_file_extension(av[1]) != 0)
		error_handling("Error: invalid file", g_ptr->map, g_ptr);
	if (validate_game_utils(g_ptr->map) != 0)
		error_handling("Error6", g_ptr->map, g_ptr);
	if (check_height_width(g_ptr) != 0)
		error_handling("Error:\ninvalid map", g_ptr->map, g_ptr);
	ft_flood_fill(g_ptr->mc, g_ptr->px, g_ptr->py);
	if (check_if_playable(g_ptr->mc) != 0)
		error_handling("Error\ninplayable game", g_ptr->map, g_ptr);
	if ((g_ptr->h > 1980) || (g_ptr->w > 1080))
		error_handling("Error:\nlarge map", g_ptr->map, g_ptr);
}
