/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_myCode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:57:09 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/05 13:39:23 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //bu printf için silinecek

char	*find_my_line(char *readStrTo)
{
	int		lc;
	int		i;
	char	*myLine;

	lc = 0;
	i = 0;
	//finding till the new line
	while(readStrTo[lc] != '\0' && readStrTo[lc] != '\n')
		lc++;
	myLine = (char *)malloc(sizeof(char) * (lc+1));
	while(readStrTo[i] != '\0' && readStrTo[i] != '\n')
	{
		myLine[i] = readStrTo[i];
		i++;
	}
	if(readStrTo[i] == '\n')
		myLine[i++] = '\n';
	myLine[i]='\0';
	return(myLine);
}

char	*readTheBuf(char *readStrTo, int fd)
{
	ssize_t	countReadBytes;
	char	*addStr;

	addStr = (char *)malloc(sizeof(char)*(BUFFER_SIZE+1));
	countReadBytes = read(fd,addStr,BUFFER_SIZE);
	printf("print read string ---->(addsTr): %s\n", addStr);
	if(countReadBytes >= 0)
		addStr[countReadBytes] = '\0';
	else
		return (NULL);
	printf("Bytes that read ----->(countReadBytes): %zd\n", countReadBytes);
	readStrTo = ft_strjoin(readStrTo,addStr);
	printf("added string ------>(addStr): %s\n", addStr);
	printf("after strjoin readStrTo ------>(readStrTo): %s\n", readStrTo);
	//free(addStr);
	return(readStrTo);
}

char	*freePreviousLine(char *readStrTo)
{
	size_t	lc;
	size_t	i;
	char	*myLine;

	i = 0;
	lc = 0;
	while(readStrTo[lc] && readStrTo[lc] != '\n')
		lc++;
	myLine = (char *)malloc(sizeof(char) * (ft_strlen(readStrTo)-lc+1));
	while(readStrTo)
		myLine[i++] = readStrTo[lc++];
	return(myLine);

}

char	*get_next_line(int fd)
{
	static char	*readStrTo;
	char		*my_line;
	printf("--------> buf read preRead ----->(readStrTo): %s\n", readStrTo);
	readStrTo = readTheBuf(readStrTo, fd);
	printf("buf read afterRead ----(readStrTo): %s\n", readStrTo);
	my_line= find_my_line(readStrTo);
	readStrTo = freePreviousLine(readStrTo);
	return(my_line);
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int	main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("fd = %d\n" ,fd);
	printf("call1--return string = %s\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call2--return string = %s\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call3--return string = %s\n----------------------------\n" ,get_next_line(fd));
	printf("fd = %d\n" ,fd);
	printf("call4--return string = %s\n----------------------------\n" ,get_next_line(fd));
	close(fd);
}
