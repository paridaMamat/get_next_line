/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:07:41 by pmaimait          #+#    #+#             */
/*   Updated: 2022/06/07 17:50:11 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_free(char *stash, char *buf)
{
	char	*to_free;

	to_free = ft_strjoin(stash, buf);
	free(stash);
	return (to_free);
}

char	*next_stash(char *stash)
{
	char	*new_stash;
	int	len;
	int	i;

	if (!stash)
	{
		free(stash);
		return (0);
	}
	len = 0;
	while(stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (0);
	}
	new_stash = ft_calloc((ft_strlen(stash) - len + 1), sizeof(char));
	len = len + 1;
	i = 0;
	while(stash[len])
		new_stash[i++] = stash[len++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
char	*generate_line(char *stash)
{
	char  *line;
	int  i;
	size_t len;

	len = 0;
	if (!stash)
		return (NULL);
	while(stash[len] && stash[len] != '\n')
		len++;
	line = ft_calloc(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buf;
	int 	read_size;

	//malloc for buf 
	if (!stash)
		stash = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while(read_size > 0 && ft_strchr(stash, '\n') == NULL)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buf);
			return(NULL);
		}
		buf[read_size] = '\0';
		stash = ft_free(stash, buf);
	}
	free(buf);
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = read_file(fd, stash);
	if(!stash)
	{
		return(NULL);
		free(stash);
	}
	line = generate_line(stash);
	if(line[0] == '\0')
	{
		free(line);
		return(NULL);
	}
	stash = next_stash(stash);
	return (line);
}