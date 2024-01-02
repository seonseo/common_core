/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:03:24 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/01 23:39:47 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char    *get_next_line(int fd)
{
    static t_fdlist *head;
    t_fdlist        *fdnode;
    char            buf[BUFFER_SIZE + 1];
    char            *newline;
    ssize_t         readbyte;

    fdnode = ft_set_fdnode(&head, fd);
    newline = NULL;
    while (1)
    {
        if ((newline = ft_strchr(fdnode->save, '\n')) != NULL)
            break;
        if ((readbyte = read(fd, buf, BUFFER_SIZE)) == -1)
            return (ft_free_fdnode(&head, fdnode));
        if (readbyte == 0)
            break;
        buf[readbyte] = '\0';
        if (ft_bufjoin(fdnode, buf) == -1)
            return (ft_free_fdnode(&head, fdnode));
    }
    return (ft_get_line(&head, fdnode, newline));
}

char    *ft_get_line(t_fdlist **head, t_fdlist *fdnode, char *newline)
{
    char    *line;
    char    *left;

    if (newline == NULL)
    {
        line = ft_substr(fdnode->save, 0, fdnode->save_size);
        ft_free_fdnode(head, fdnode);
        return (line);
    }
    line = ft_substr(fdnode->save, 0, newline + 1 - fdnode->save);
    if (line == NULL)
        return (ft_free_fdnode(head, fdnode));
    fdnode->save_len = ft_strlen(newline + 1);
    fdnode->save_size = fdnode->save_len + 1;
    left = ft_substr(newline + 1, 0, fdnode->save_len);
    if (left == NULL)
    {
        free(line);
        line = NULL;
        return (ft_free_fdnode(head, fdnode));
    }
    free(fdnode->save);
    fdnode->save = left;
    return (line);
}

t_fdlist    *ft_set_fdnode(t_fdlist **head, int fd)
{
    t_fdlist    *curr;
    t_fdlist    *prev;

    curr = *head;
    prev = NULL;
    while (curr && curr->fd != fd)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        curr = (t_fdlist *)malloc(sizeof(t_fdlist));
        curr->fd = fd;
        curr->save = NULL;
        curr->save_len = 0;
        curr->save_size = 0;
        if (*head != NULL)
            prev->next = curr;
        else
            *head = curr;
    }
    return (curr);
}

void    *ft_free_fdnode(t_fdlist **head, t_fdlist *fdnode)
{
    t_fdlist  *curr;
    t_fdlist  *prev;

    curr = *head;
    prev = NULL;
    while (curr && curr != fdnode)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == fdnode)
    {
        if (*head == fdnode)
            *head = NULL;
        else
            prev->next = curr->next;
        free(curr->save);
        curr->save = NULL;
        free(curr);
        curr = NULL;
    }
    return (NULL);
}

int ft_bufjoin(t_fdlist *fdnode, char *buf)
{
	char	*joinstr;
	size_t	joinlen;

	joinlen = fdnode->save_len + ft_strlen(buf);
    if (fdnode->save_size < joinlen + 1)
    {
        if (fdnode->save_size == 0)
            fdnode->save_size = joinlen + 1;
        while (fdnode->save_size < joinlen + 1)
            fdnode->save_size *= 2;
	    joinstr = (char *)malloc(sizeof(char) * fdnode->save_size);
        if (joinstr == NULL)
            return (-1);
        ft_strlcpy(joinstr, fdnode->save, fdnode->save_size);
        free(fdnode->save);
        fdnode->save = joinstr;
    }
	ft_strlcpy(fdnode->save + fdnode->save_len, buf, fdnode->save_size);
    fdnode->save_len = joinlen;
	return (0);
}

#include <stdio.h>

int main(void)
{
    int fd[2];
    int i;

    fd[0] = open("text", O_RDONLY);
    i = 0;
    while (i < 7)
    {
        printf("%s", get_next_line(fd[0]));
        i++;
    }
    close(fd[0]);
    return (0);
}
