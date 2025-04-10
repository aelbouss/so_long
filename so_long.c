/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:21:43 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 16:00:22 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		puterror("Error:\ninvalid arguments");
	game = malloc(sizeof(t_game));
	if (!game)
		puterror("Bad Allocation");
	initialize_utils(game, av);
	map_parsing(game, av);
	initialize_game(game);
}
