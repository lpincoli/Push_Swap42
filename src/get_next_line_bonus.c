/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:43 by rfrangin          #+#    #+#             */
/*   Updated: 2022/11/09 15:26:44 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line_bonus.h"
#include <limits.h>

static char	*get_buf(int fd, char *buf, char *fub)
{
	char	*tmp;
	int		count;

	count = 1;
	while (count != '\0')
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buf[count] = '\0';
		if (!fub)
			fub = ft_strdup("");
		tmp = fub;
		fub = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (fub);
}

static char	*get_line(char *print)
{
	size_t	i;
	char	*line;

	i = 0;
	while (print[i] != '\0' && print[i] != '\n')
		i++;
	if (print[i] == '\0' || print[1] == '\0')
		return (0);
	line = ft_substr(print, i + 1, ft_strlen(print) - i);
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	print[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{	
	static char	*fub[FOPEN_MAX];
	char		*buf;
	char		*print;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	print = get_buf(fd, buf, fub[fd]);
	free(buf);
	buf = NULL;
	if (!print)
		return (NULL);
	fub[fd] = get_line(print);
	return (print);
}
