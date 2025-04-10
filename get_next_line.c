/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:07:54 by aelbouss          #+#    #+#             */
/*   Updated: 2025/04/10 15:08:14 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*one_line(char *string)
{
	char	*line;
	int		i;
	int		last_char;

	i = 0;
	last_char = 1;
	if (!string || string[i] == '\0')
		return (NULL);
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\n')
		last_char = 2;
	line = (char *)malloc((i * sizeof(char)) + last_char);
	if (!line)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
	{
		line[i] = string[i];
		i++;
	}
	line[i] = string[i];
	if (string[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

char	*read_buff(int fd, char *buff, char *string)
{
	int		offset;
	char	*temp;

	offset = 1;
	while (offset > 0)
	{
		offset = read(fd, buff, BUFFER_SIZE);
		if (offset == 0)
			break ;
		buff[offset] = '\0';
		if (!string)
			string = ft_strdup("");
		temp = string;
		string = ft_strjoin(temp, buff);
		free(temp);
		if (!string)
			return (NULL);
		if ((ft_strchr(string, '\n')) == 1)
			break ;
	}
	if (offset == -1)
		return (NULL);
	return (string);
}

char	*remaining_data(char *string)
{
	char	*newstring;
	int		i;

	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	i++;
	newstring = ft_strdup(&string[i]);
	free(string);
	return (newstring);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*linebuff;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buff)
		return (NULL);
	string = read_buff(fd, buff, string);
	free(buff);
	if (!string)
		return (NULL);
	linebuff = one_line(string);
	string = remaining_data(string);
	return (linebuff);
}
