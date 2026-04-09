/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:28:12 by zachamou          #+#    #+#             */
/*   Updated: 2023/06/21 13:37:35 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_get_line(char *line)
{
	char	*gline;
	int		i;

	i = 0;
	while (line[i] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	gline = malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		gline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		gline[i] = line[i];
		i++;
	}
	gline[i] = '\0';
	return (gline);
}

char	*next_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*check_buff(int fd, char *line)
{
	char	*buff;
	int		pos_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	pos_read = 1;
	while (!ft_strchr(line, '\n') && pos_read > 0)
	{
		pos_read = read(fd, buff, BUFFER_SIZE);
		if (pos_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[pos_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = check_buff(fd, line[fd]);
	if (line[fd] == NULL)
		return (NULL);
	str = read_get_line(line[fd]);
	line[fd] = next_line(line[fd]);
	return (str);
}

/*
int main(void)
{
	char *line;
	int fd[3];
	int i;

	fd[0] = open("file1.txt", O_RDONLY);
	fd[1] = open("file2.txt", O_RDONLY);
	fd[2] = open("file3.txt", O_RDONLY);

	for (i = 0; i < 3; i++)
	{
		while ((line = get_next_line(fd[i])) != NULL)
		{
			printf("%s\n", line);
			free(line);
		}

		close(fd[i]);
	}
	return (0);
}	
*/
