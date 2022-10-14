/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.count                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:57:09 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/06 12:52:46 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*takeline(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*my_next_line(char *save)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	count = 0;
	while (save[i])
		str[count++] = save[i++];
	str[count] = '\0';
	free(save);
	return (str);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = takeline(save);
	save = my_next_line(save);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
int	main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n" ,fd);
	printf("call1--return string = %str\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call2--return string = %str\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call3--return string = %str\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call4--return string = %str\n----------------------------\n" ,get_next_line(fd));
	close(fd);
}
*/
