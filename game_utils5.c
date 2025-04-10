/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:01:13 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:01:54 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_up(t_game *g, t_img *i)
{
	char	*msg;

	msg = "Bad Allocation";
	clean_2d_arr(g->map);
	clean_2d_arr(g->mc);
	mlx_destroy_image(g->mlx, i->player);
	mlx_destroy_image(g->mlx, i->wall);
	mlx_destroy_image(g->mlx, i->collectible);
	mlx_destroy_image(g->mlx, i->exit);
	mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	free(g);
	free(i);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

t_all	*create_container(t_game *ga, t_img *im)
{
	t_all	*a;

	a = malloc(sizeof(t_all));
	if (!a)
		ft_free_up(ga, im);
	a->g = ga;
	a->i = im;
	return (a);
}

void	ft_clean_container(t_all *a)
{
	clean_2d_arr(a->g->map);
	clean_2d_arr(a->g->mc);
	mlx_destroy_window(a->g->mlx, a->g->win);
	mlx_destroy_image(a->g->mlx, a->i->player);
	mlx_destroy_image(a->g->mlx, a->i->wall);
	mlx_destroy_image(a->g->mlx, a->i->collectible);
	mlx_destroy_image(a->g->mlx, a->i->exit);
	mlx_loop_end(a->g->mlx);
	free(a->g->mlx);
	free(a->g);
	free(a->i);
	free(a);
	exit(EXIT_FAILURE);
}

void	ft_error_case(t_all *a, char *msg)
{
	ft_clean_container(a);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
