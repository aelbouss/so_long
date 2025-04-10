/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:04:54 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:06:11 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	right_process(t_all *p, int *c, int y, int x)
{
	char	holder;

	character_pos(p, &p->g->ey, &p->g->ex, 'E');
	if (p->g->map[y][x + 1] == 'E' && p->g->cc == 0)
		ft_clean_container(p);
	if (p->g->map[y][x + 1] == 'C')
		p->g->cc--;
	holder = p->g->map[y][x];
	p->g->map[y][x + 1] = holder;
	if (x == p->g->ex && y == p->g->ey)
		p->g->map[y][x] = 'E';
	else
		p->g->map[y][x] = '0';
	draw_sprites(p->g, p->i);
	*c = *c + 1;
	ft_putnbr(*c);
	write(1, "\n", 1);
}

void	left_process(t_all *p, int *c, int y, int x)
{
	char	holder;

	character_pos(p, &p->g->ey, &p->g->ex, 'E');
	if (p->g->map[y][x - 1] == 'E' && p->g->cc == 0)
		ft_clean_container(p);
	if (p->g->map[y][x - 1] == 'C')
		p->g->cc--;
	holder = p->g->map[y][x];
	if (x == p->g->ex && y == p->g->ey)
		p->g->map[y][x] = 'E';
	else
		p->g->map[y][x] = '0';
	p->g->map[y][x - 1] = holder;
	draw_sprites(p->g, p->i);
	*c = *c + 1;
	ft_putnbr(*c);
	write(1, "\n", 1);
}

void	player_pos(t_game *g, int *yp, int *xp)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				*yp = y;
				*xp = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_if_playable(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
				return (-1);
			if (map[y][x] == 'C')
				return (-1);
			if (map[y][x] == 'E')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
