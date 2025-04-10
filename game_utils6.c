/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:01:59 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:03:05 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_pos(t_all *a, int *yp, int *xp, char c)
{
	int	y;
	int	x;

	y = 0;
	while (a->g->map[y])
	{
		x = 0;
		while (a->g->map[y][x])
		{
			if (a->g->map[y][x] == c)
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

void	move_up(t_all *p, int *c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	character_pos(p, &y, &x, 'P');
	if (p->g->map[y][x])
	{
		if (p->g->map[y - 1][x] && p->g->map[y - 1][x] != '1')
			up_process(p, c, y, x);
	}
}

void	move_down(t_all *p, int *c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	character_pos(p, &y, &x, 'P');
	if (p->g->map[y][x])
	{
		if (p->g->map[y + 1][x] && p->g->map[y + 1][x] != '1')
			down_process(p, c, y, x);
	}
}

void	move_right(t_all *p, int *c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	character_pos(p, &y, &x, 'P');
	if (p->g->map[y][x])
	{
		if (p->g->map[y][x + 1] && p->g->map[y][x + 1] != '1')
			right_process(p, c, y, x);
	}
}

void	move_left(t_all *p, int *c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	character_pos(p, &y, &x, 'P');
	if (p->g->map[y][x])
	{
		if (p->g->map[y][x - 1] && p->g->map[y][x - 1] != '1')
			left_process(p, c, y, x);
	}
}
