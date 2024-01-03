/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:03:28 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/03 21:38:11 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_fdlist
{
	int				fd;
	char			*save;
	size_t			save_len;
	size_t			save_size;
	struct s_fdlist	*next;
}	t_fdlist;

char		*get_next_line(int fd);
char		*ft_get_line(t_fdlist **head, t_fdlist *fdnode, char *newline);
int			ft_get_left(t_fdlist **head, t_fdlist *fdnode, char *newline);
t_fdlist	*ft_set_fdnode(t_fdlist **head, int fd);
void		*ft_free_fdnode(t_fdlist **head, t_fdlist *fdnode);
int			ft_bufjoin(t_fdlist *fdnode, char *buf);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
