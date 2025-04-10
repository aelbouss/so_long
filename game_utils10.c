/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:06:16 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:07:36 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	helper(char **map, int *a, int x, int y)
{
	if (map[y][x] == '1')
		a[0] = a[0] + 1;
	if (map[y][x] == '0')
		a[1] = a[1] + 1;
	if (map[y][x] == 'P')
		a[2] = a[2] + 1;
	if (map[y][x] == 'E')
		a[3] = a[3] + 1;
	if (map[y][x] == 'C')
		a[4] = a[4] + 1;
}

int	check_chars_existence(char **map)
{
	int	x;
	int	y;
	int	a[5];

	y = 0;
	while (y < 5)
		a[y++] = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			helper(map, a, x, y);
			x++;
		}
		y++;
	}
	if (a[0] == 0 || a[1] == 0 || a[2] == 0 || a[3] == 0 || a[4] == 0)
		return (-1);
	if (a[2] > 1 || a[3] > 1)
		return (-1);
	return (0);
}

size_t	len_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	sub_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}
