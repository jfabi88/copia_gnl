/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:31:15 by mmurello          #+#    #+#             */
/*   Updated: 2021/01/31 15:23:13 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			*(char *)(dest + i - 1) = *(char *)(src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

char	*s_clear(char *s)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == 0)
	{
		free(s);
		return (0);
	}
	if (!(tmp = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (0);
	j = 0;
	i = i + 1;
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	free(s);
	return (tmp);
}

char	*s_join(char *s1, char *s2)
{
	char	*joined;
	int		len1;
	int		len2;
	int		tot_len;

	if (s1 == NULL && s2 == NULL)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tot_len = len1 + len2 + 1;
	if (!(joined = malloc(sizeof(char) * tot_len)))
		return (0);
	ft_memmove(joined, s1, len1);
	ft_memmove(joined + len1, s2, len2);
	joined[tot_len - 1] = '\0';
	free(s1);
	return (joined);
}

int		new_line(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cpy_line(char *str)
{
	char	*line;
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (!(line = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		line[len] = str[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}
