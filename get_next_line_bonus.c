/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:09:54 by jg                #+#    #+#             */
/*   Updated: 2021/11/09 12:57:38 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rem(char *rem)
{
	int	i;

	i = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	if (rem[i] == '\0')
	{
		free(rem);
		return (NULL);
	}
	rem = ft_strcpy(rem, &rem[i + 1]);
	if (rem == NULL)
		return (NULL);
	return (rem);
}

char	*ft_line(char *rem)
{
	char	*line;
	int		i;

	if (rem[0] == '\0')
		return (NULL);
	i = 0;
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	if (rem[i] == '\n')
		line[i] = '\n';
	while (i)
	{
		i--;
		line[i] = rem[i];
	}
	return (line);
}

char	*ft_read(int fd, char *buf, char *rem)
{
	int	i;

	i = 1;
	if (!rem)
		rem = (char *)ft_calloc(1, sizeof(char));
	while (i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			free(rem);
			return (NULL);
		}
		buf[i] = '\0';
		rem = ft_strjoin(rem, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem[256];
	char		*line;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rem[fd] = ft_read(fd, buf, rem[fd]);
	if (buf)
		free(buf);
	if (!rem[fd])
		return (NULL);
	line = ft_line(rem[fd]);
	rem[fd] = ft_rem(rem[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	char	*str;

	str = "key";
	fd_1 = open("text_1.txt", O_RDONLY);
	fd_2 = open("text_2.txt", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd_1);
		if (str != NULL)
			printf("%s", str);
		free(str);
		str = get_next_line(fd_2);
		if (str != NULL)
			printf("%s", str);
		free(str);
	}
	return (0);
}
*/