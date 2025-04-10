/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:56:40 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:01:07 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

void	open_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, ((game->w) * 64),
			((game->h) * 64), "so_long");
}

void	draw_sprites(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->h)
	{
		j = 0;
		while (j < game->w)
		{
			if (game->map[i][j] == '0')
				put_image(game, img->nothing, j, i);
			else if (game->map[i][j] == '1')
				put_image(game, img->wall, j, i);
			else if (game->map[i][j] == 'C')
				put_image(game, img->collectible, j, i);
			else if (game->map[i][j] == 'E')
				put_image(game, img->exit, j, i);
			else if (game->map[i][j] == 'P')
			{
				put_image(game, img->player, j, i);
			}
			j++;
		}
		i++;
	}
}

void	initialize_game(t_game	*game)
{
	t_img	*image;
	t_all	*all;

	image = allocate_sprites(game);
	if (!image)
		error_handling("Bad Allocation", game->map, game);
	open_window(game);
	draw_sprites(game, image);
	all = create_container(game, image);
	mlx_key_hook(game->win, event_handling, all);
	mlx_loop(game->mlx);
}

char	**copy_map(t_game *game)
{
	char	**cm;
	int		i;

	cm = malloc(sizeof(char *) * (game->h + 1));
	if (!cm)
		return (NULL);
	i = 0;
	while (game->map[i])
	{
		cm[i] = ft_strdup(game->map[i]);
		if (!cm[i])
		{
			clean_2d_arr(cm);
			return (NULL);
		}
		i++;
	}
	cm[i] = NULL;
	return (cm);
}
