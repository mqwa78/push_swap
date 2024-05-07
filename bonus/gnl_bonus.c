/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:39:43 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 02:53:08 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = 0;
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_read(int fd, char *line)
{
	int		r;
	char	*buff;

	r = 1;
	buff = malloc(sizeof(char) * (1 + 1));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	while (r > 0 && !ft_strchr(buff, '\n'))
	{
		r = read(fd, buff, 1);
		if (r < 0)
		{
			free(buff);
			return (NULL);
		}
		if (r > 0)
		{
			buff[r] = 0;
			line = ft_strjoin(line, buff);
		}
	}
	free(buff);
	return (line);
}

char	*ft_gnl(int fd)
{
	char	*line;
	char	*line2;

	line2 = NULL;
	if (fd < 0)
		return (NULL);
	line = ft_read(fd, line2);
	return (line);
}
