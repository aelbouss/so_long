/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:53:19 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:12:38 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	it_has_char(char c, t_game *p)
{
	char	*chars;
	int		i;

	chars = "10PEC";
	i = 0;
	while (i <= p->w - 2)
	{
		if (c == chars[i])
			return (1);
		i++;
	}
	return (-1);
}

int	check_file_extension(char *file)
{
	int		i;
	int		idx;
	char	*extension;

	i = (ft_strlen(file) - 1);
	extension = ".ber";
	idx = 3;
	if (ft_strlen(file) >= 5 && file[ft_strlen(file) - 5] != '/')
	{
		while (i >= i - 4 && idx >= 0)
		{
			if (file[i] != extension[idx])
				return (-1);
			i--;
			idx--;
		}
	}
	else
		return (-1);
	return (0);
}

int	validate_game_utils(char **map)
{
	int	arr[3];
	int	i;
	int	j;

	i = 0;
	while (i < 3)
		arr[i++] = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			fill_arr(map, arr, i, j);
			j++;
		}
		i++;
	}
	if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0)
		return (0);
	return (-1);
}

int	check_height_width(t_game *game)
{
	if (game->h < 3)
		return (-1);
	if (game->w < 3)
		return (-1);
	return (0);
}

t_img	*allocate_sprites(t_game *game)
{
	t_img	*sprites;

	sprites = malloc(sizeof(t_img));
	if (!sprites)
		return (NULL);
	sprites->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &sprites->w, &sprites->h);
	if (!sprites->player)
		ft_destroy_game(game,sprites, 'A');
	sprites->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &sprites->w, &sprites->h);
	if (!sprites->wall)
		ft_destroy_game(game,sprites, 'B');
	sprites->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &sprites->w, &sprites->h);
	if (!sprites->exit)
		ft_destroy_game(game,sprites, 'C');
	sprites->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &sprites->w, &sprites->h);
	if (!sprites->collectible)
		ft_destroy_game(game,sprites, 'D');
	sprites->nothing = mlx_xpm_file_to_image(game->mlx,
			"textures/nothing.xpm", &sprites->w, &sprites->h);
	if (!sprites->nothing)
		ft_destroy_game(game, sprites, 'E');
		
	return (sprites);
}
