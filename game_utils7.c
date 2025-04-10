/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:03:15 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:11:43 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event_handling(int keycode, t_all *a)
{
	static int	cnt;

	if (keycode == 97)
		move_left(a, &cnt);
	else if (keycode == XK_d)
		move_right(a, &cnt);
	else if (keycode == 119)
		move_up(a, &cnt);
	else if (keycode == 115)
		move_down(a, &cnt);
	else if (keycode == XK_Escape)
		ft_clean_container(a);
	return (0);
}

void	fill_arr(char **map, int *a, int i, int j)
{
	if (map[i][j] == 'C')
		a[0] += 1;
	else if (map[i][j] == 'E')
		a[1] += 1;
	else if (map[i][j] == 'P')
		a[2] += 1;
}

void	initial_clear(t_game *g)
{
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g);
	puterror("Error:\ninvalid map");
}

void	ft_cleaner0(t_game *g, t_img*i, char *msg)//works  good
{
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
}

void	ft_destroy_game(t_game *g, t_img *i, char flag)
{
	if (flag == 'A')
		ft_cleaner0(g, i, "Bad Allocation");
	if (flag == 'B')
		ft_cleaner1(g,i,"Bad allocation");
	if (flag == 'C')
		ft_cleaner2(g, i,"Bad allocation");
	if (flag == 'D')
		ft_cleaner3(g,i,"Bad allocation");
	if (flag == 'E')
		ft_cleaner4(g,i,"Bad allocation");
	exit(EXIT_FAILURE);
}