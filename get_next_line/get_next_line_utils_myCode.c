/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_myCode.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:25 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/04 10:19:02 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0' && str)
	{
		a++;
	}
	return (a);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	char	*ns1;
	char	*ns2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ns1 = (char *)s1;
	ns2 = (char *)s2;
	if(!ns1)
		{
			ns1 = (char *)malloc(1);
			ns1[0] = 0;
		}
	if (!ns1 && !ns2)
		return (0);
	ns = (char *)malloc(sizeof(char) * (ft_strlen(ns1) + ft_strlen(ns2) + 1));
	if (!ns)
		return (0);
	while (*(ns1 + j))
		*(ns + i++) = *(ns1 + j++);
	j = 0;
	while (*(ns2 + j))
		*(ns + i++) = *(ns2 + j++);
	*(ns + i) = '\0';
	return (ns);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (0);
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*src;
	size_t	i;

	i = 0;
	src = (char *)s;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (0);
		*ret = '\0';
	}
	else
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (!ret)
			return (0);
		ft_strlcpy(ret, &src[start], len + 1);
	}
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (src[j] && j + 1 < dstsize)
	{
		dst[j] = src [j];
		j++;
	}
	if (dstsize != 0)
		dst[j] = '\0';
	return (i);
}
