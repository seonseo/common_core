/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:03:24 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/02 14:31:43 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *save;
    char        buf[BUFFER_SIZE + 1];
    char        *join;
    char        *newline;
    ssize_t     readbyte;

    newline = NULL;
    while (1)
    {
        if ((newline = ft_strchr(save, '\n')) != 0)
            break;
        if ((readbyte = read(fd, buf, BUFFER_SIZE)) == -1)
            return (ft_free(&save));
        if (readbyte == 0)
            break;
        buf[readbyte] = '\0';
        if((join = ft_strjoin(save, buf)) == NULL)
            return (ft_free(&save));
        free(save);
        save = join;
    }
    return (ft_get_line(&save, newline));
}


char    *ft_get_line(char **save, char *newline)
{
    char    *line;
    char    *left;

    if (newline == NULL)
    {
        if (*save == NULL)
            line = NULL;
        else
            line = ft_strdup(*save);
        ft_free(save);
        return (line);
    }
    line = ft_substr(*save, 0, newline + 1 - *save);
    if (line == NULL)
        return (ft_free(save));
    left = ft_strdup(newline + 1);
    if (left == NULL)
    {
        free(line);
        line = NULL;
        return (ft_free(save));
    }
    free(*save);
    *save = left;
    return (line);
}

void    *ft_free(char **s)
{
    free(*s);
    *s = NULL;
    return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcpy(str + ft_strlen(s1), s2, size);
	return (str);
}

#include <stdio.h>

int main(void)
{
    int fd;
    int i;
    
    fd = open("text", O_RDONLY);
    i = 0;
    while (i < 6)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    close(fd);
    return (0);
}