/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:09:42 by youbella          #+#    #+#             */
/*   Updated: 2025/01/02 10:35:40 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < count * size)
		p[i++] = 0;
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	p = ft_calloc(len, 1);
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i] && i < len - 1)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	p = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!p)
		return (free(s1), NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	return (free(s1), p);
}
