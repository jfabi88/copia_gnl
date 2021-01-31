/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:32:33 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/31 20:10:15 by kizura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "stdlib.h"

char	*copia(char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s2 == 0)
		return (s1);
	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] !=  0)
		i++;
	return (i);
}


char	*first_allocation(char *p, char *buffer)
{
	int i;

	i = 0;
	//printf("inziialmente il punattore in firs_allocation e: %p\n", &p);
	if (p != 0)
	{
		free(p);
			p = 0;
	}
	while(buffer[i] != '\n' && buffer[i])
		i++;
	p = malloc(i + 1);
	//printf("il puntatore in prima allocazione e: %p\n", &p);
	if (p == 0)
		return (0);
	p[0] = 0;
	//printf("successivamente in fisrt allocation il punattore e: %p\n", &p);
	return (p);
}


char	*allocazione_line(char *p, char *buffer)
{
	size_t i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	//char	temp[ft_strlen(p) + 1];
	//int		i;

	//i = 0;
	//temp = malloc(sizeof(char) * (ft_strlen(p) + 1));
	//if (temp == 0)
	//	return (NULL);
	//copia(temp, p);
	//printf("in allocazione la temp e: %p\n", &temp);
	//if (p != 0)
	//	free(p);
	//p = malloc(sizeof(char) * (ft_strlen(temp) + BUFFER_SIZE + 1));
	//printf("il puntatpore in allocazione e: %p\n", &p);
	//if (p == 0)
	//	return (NULL);
	//while (temp[i] != 0)
	//{
	//	p[i] = temp[i];
	//	i++;
	//}
	//p[i] = 0;
	//free(temp);
	//printf("inizilamente in allocazione il punattore e: %p\n", &p);
	p = realloc(p, ft_strlen(p) + i + 1);
	if (p == 0)
		return (0);
	//printf("successivamente il punattore in allocazione e: %p\n", &p);
	//if (p == 0)
	//	return (0);
	return (p);
}

char	*join_modificato(char *p,char **matrix, int fd, int *ret)
{
	int	i;
	int	j;
	int k;

	j = ft_strlen(p);
	i = 0;
	//printf("il punattore ret e: %p\n", &ret);
	*ret = 0;
	while (matrix[fd][i] != 0 && matrix[fd][i] != '\n')
	{
		p[i + j] = matrix[fd][i];
		i++;
	}
	p[i + j] = 0;
	if (matrix[fd][i] == '\n')
	{
		*ret = 1;
		i++;
	}
	k = 0;
	while(matrix[fd][i] != 0)
	{
		matrix[fd][k] = matrix[fd][i];
		k++;
		i++;
	}
	while(matrix[fd][k] != 0)
	{
		matrix[fd][k] = 0;
		k++;
	}
	matrix[fd][k] = 0;
	return (p);
}

//void	free_matrix_fd(char *str, char *line)
//{
	//if (line != 0)
	//	free(line);
	//line = realloc(line, 1);
	//	if (line == NULL)
	//		return ;
	//printf("la lien in frree_matrix e: %p\n", &line);
//	line[0] = 0;
	//printf("il puntatore str in free_matrix e: %p\n", &str);
	//if (str != 0)
	//{
	//	free(str);
	//	str = NULL;
	//}
//}

int		get_next_line(int fd, char **line)
{
	static char	*matrix[255];
	int			ret;

	//printf("la amtricce globale e: %p\n", &matrix);
	if (fd < 0 || fd > 255 || BUFFER_SIZE < 0)
		return (-1);
	if (matrix[fd] == 0)
	{
	   matrix[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	   matrix[fd][0] = 0;
  		matrix[fd][BUFFER_SIZE] = 0;

	}
	if (matrix[fd] == 0)
		return (-1);
	//printf("la matrice fd e: %p\n", &matrix[fd]);
	if ((*line = first_allocation(*line, matrix[fd])) == NULL)
		return (-1);
	//printf("la linea totale e: %p:183\n", &(line));
	//printf("la line e: %p\n", &(*line));
	*line = join_modificato(*line, matrix, fd, &ret);
	//printf("la ret e: %p\n", &ret);
	//printf("la line e: %p\n", &(*line));
	if (ret == 1)
		return (1);
	while (read(fd, matrix[fd], BUFFER_SIZE) > 0)
	{
		//printf("la matirce dopo read e: %p\n", &matrix[fd]);
		int i;
		i = 0;
		if ((*line = allocazione_line(*line, matrix[fd])) == NULL)
			return (-1);
		*line = join_modificato(*line, matrix, fd, &ret);
		if (ret == 1)
			return (1);
		while (i < BUFFER_SIZE)
		{
			matrix[fd][i] = 0;
			i++;
		}
	}
//	if (*line != 0)
//	{
//		free(*line);
//		*line = 0;
//	}
//	if (matrix[fd] != 0)
//	{
//		free(matrix[fd]);
//		matrix[fd] = 0;
//	}
	//printf("la lie 2 e: %p\n", &(*line));
	free(matrix[fd]);
	matrix[fd] = 0;
	if (*line == NULL)
		return (-1);
	//printf("la line e': %p\n", &(*line));
	//printf("ciao");
	return (0);
}
