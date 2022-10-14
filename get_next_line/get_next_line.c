/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:57:09 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/11 13:05:03 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *save)
{
	char	*buff;
	ssize_t	read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*takeline(char *save)
{
	char	*myline;
	int		i;

	i = 0;
	if (save[i] == '\0')
		return (0);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	myline = (char *)malloc(sizeof(char) * (i + 2));
	if (!myline)
		return (0);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		myline[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		myline[i] = '\n';
		i++;
	}
	myline[i] = '\0';
	return (myline);
}

char	*mynextline(char *save)
{
	char	*nextline;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (0);
	}
	nextline = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!nextline)
		return (0);
	i++;
	j = 0;
	while (save[i] != '\0')
		nextline[j++] = save[i++];
	nextline[j] = '\0';
	free(save);
	return (nextline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	save = read_and_save(fd, save);
	if (!save)
		return (0);
	line = takeline(save);
	save = mynextline(save);
	return (line);
}
