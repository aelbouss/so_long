/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:03:30 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:04:23 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1 ;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	cnt_collectibles(t_game *g)
{
	int	y;
	int	x;
	int	cnt;

	y = 0;
	cnt = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				cnt++;
			x++;
		}
		y++;
	}
	return (cnt);
}

void	up_process(t_all *p, int *c, int y, int x)
{
	char	holder;

	character_pos(p, &p->g->ey, &p->g->ex, 'E');
	if (p->g->map[y - 1][x] == 'E' && p->g->cc == 0)
		ft_clean_container(p);
	if (p->g->map[y - 1][x] == 'C')
		p->g->cc--;
	holder = p->g->map[y][x];
	p->g->map[y - 1][x] = holder;
	if (x == p->g->ex && y == p->g->ey)
		p->g->map[y][x] = 'E';
	else
		p->g->map[y][x] = '0';
	draw_sprites(p->g, p->i);
	*c = *c + 1;
	ft_putnbr(*c);
	write(1, "\n", 1);
}

void	down_process(t_all *p, int *c, int y, int x)
{
	char	holder;

	character_pos(p, &p->g->ey, &p->g->ex, 'E');
	if (p->g->map[y + 1][x] == 'E' && p->g->cc == 0)
		ft_clean_container(p);
	if (p->g->map[y + 1][x] == 'C')
		p->g->cc--;
	holder = p->g->map[y][x];
	p->g->map[y + 1][x] = holder;
	if (x == p->g->ex && y == p->g->ey)
		p->g->map[y][x] = 'E';
	else
		p->g->map[y][x] = '0';
	draw_sprites(p->g, p->i);
	*c = *c + 1;
	ft_putnbr(*c);
	write(1, "\n", 1);
}
