/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: horarivo <horarivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:16:53 by horarivo          #+#    #+#             */
/*   Updated: 2026/03/07 10:35:31 by horarivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *static_var)
{
	int		i;
	char	*str_to_return;

	if (!static_var)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
		i++;
	str_to_return = (char *)malloc(sizeof(char) * (i + 2));
	if (!str_to_return)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
	{
		str_to_return[i] = static_var[i];
		i++;
	}
	if (static_var[i] == '\n')
	{
		str_to_return[i] = '\n';
		i++;
	}
	str_to_return[i] = '\0';
	return (str_to_return);
}

char	*ft_readline(int fd, char *line)
{
	char	*buffer;
	int		flag;
	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	flag = 1;
	while ((!line || !ft_strchr(line, '\n')) && flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[flag] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
	}
	free(buffer);
	return (line);
}

char	*ft_left(char *static_var)
{
	int		i;
	char	*left;

	if (!static_var)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
		i++;
	if (!static_var[i])
	{
		free(static_var);
		return (NULL);
	}
	i++;
	left = ft_substr(static_var, i, ft_strlen(static_var) - i);
	free(static_var);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*static_var[1024];
	char		*line_to_return ;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_var[fd] = ft_readline(fd, static_var[fd]);
	if (!static_var[fd] || *static_var[fd] == '\0')
	{
		if (static_var[fd])
			free(static_var[fd]);
		static_var[fd] = NULL;
		return (NULL);
	}
	line_to_return = ft_getline(static_var[fd]);
	static_var[fd] = ft_left(static_var[fd]);
	return (line_to_return);
}
