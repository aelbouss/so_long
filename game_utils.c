/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:52:07 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 14:53:06 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	cnt_lines(char	*file)
{
	char	*str;
	size_t	cnt;
	int		fd;

	fd = open(file, O_RDONLY);
	str = NULL;
	cnt = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		cnt++;
		free(str);
	}
	close(fd);
	return (cnt);
}

void	puterror(char	*msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	clean_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**read_map(char	*file, t_game *p)
{
	char	**map;
	int		fd;
	int		i;
	char	*line;

	map = malloc((p->h + 1) * sizeof(char *));
	if (!map)
		puterror("Bad Allocation");
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		puterror("Invalid file descriptor");
		clean_2d_arr(map);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strdup(line);
		free(line);
	}
	map[i] = NULL;
	return (map);
}

void	initialize_utils(t_game *utils, char **av)
{
	utils->mlx = mlx_init();
	utils->h = cnt_lines(av[1]);
	if (utils->h < 3)
		initial_clear(utils);
	utils->map = read_map(av[1], utils);
	utils->w = len_line(utils->map[0]);
	utils->cc = cnt_collectibles(utils);
	utils->mc = copy_map(utils);
	player_pos(utils, &utils->py, &utils->px);
}
