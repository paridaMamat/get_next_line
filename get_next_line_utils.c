/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:08:15 by pmaimait          #+#    #+#             */
/*   Updated: 2022/06/07 15:47:59 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;
	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char  *s1, char  *s2)
{
        char    *str;
        size_t  i;
        size_t  j;

        str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!str)
                return (NULL);
        i = 0;
        j = 0;
        while (s1[i])
        {
                str[j++] = s1[i];
                i++;
        }
        i = 0;
        while (s2[i])
        {
                str[j++] = s2[i];
                i++;
        }
        str[j] ='\0';
        return (str);
}

char	*ft_strchr( const char *s, int c)
{
	unsigned int	i;
	if(!s)
		return(NULL);
	i = 0;

	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*(ptr++) = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb && !size)
		return (NULL);
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}