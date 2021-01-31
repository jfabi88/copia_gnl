/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:24:51 by mmurello          #+#    #+#             */
/*   Updated: 2021/01/31 15:02:20 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*s_clear(char *s);
char		*s_join(char *s1, char *s2);
int			new_line(char *str);
char		*cpy_line(char *str);
int			ft_strlen(char *str);

#endif
