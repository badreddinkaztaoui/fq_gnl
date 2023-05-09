/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:01:57 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/05/09 16:47:21 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!newline_exist(stash) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && readed == 0) || readed == -1)
			return (free(buff), NULL);
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *stash, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!stash[i])
		return (free(stash), NULL);
	j = 0;
	while (stash[i++])
		j++;
	rest = malloc(sizeof(char) * (j + 1));
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	return (free(stash), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	temp = read_file(fd, stash[fd]);
	if (!temp)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = temp;
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_get_rest(stash[fd], line);
	return (line);
}
