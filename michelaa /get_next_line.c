/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:31:18 by mmurello          #+#    #+#             */
/*   Updated: 2021/01/31 14:59:30 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	int				count;
	static char		*save;
	char			*buf;

	count = BUFFER_SIZE;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while (!new_line(save) && count != 0)
	{
		if ((count = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[count] = '\0';
		save = s_join(save, buf);
	}
	free(buf);
	*line = cpy_line(save);
	save = s_clear(save);
	if (count == 0)
		return (0);
	return (1);
}
