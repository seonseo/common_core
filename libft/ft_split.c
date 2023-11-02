/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:34:57 by seonseo           #+#    #+#             */
/*   Updated: 2023/11/02 18:37:17 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_split(char *s, char *start, char **strs)
{
	*strs = (char *)malloc(sizeof(char) * (s - start + 1));
	if (*strs == NULL)
		return (1);
	ft_strlcpy(*strs, start, (s - start));
	return (0);
}

static int	ft_wordlen(char *s, char c, char **strs)
{
	char	*start;

	start = NULL;
	while (*s)
	{
		if (*s != c && start == NULL)
			start = s;
		else if (*s == c && start != NULL)
		{
			if (ft_word_split(s, start, strs))
				return (1);
			strs++;
			start = NULL;
		}
		s++;
	}
	if (start != NULL && ft_word_split(s, start, strs))
		return (1);
	return (0);
}

static size_t	ft_wordcount(char *s, char c)
{
	size_t	wordcount;
	int		is_word;

	wordcount = 0;
	is_word = FALSE;
	while (*s)
	{
		if (*s != c && is_word == FALSE)
		{
			is_word = TRUE;
			wordcount++;
		}
		if (*s == c)
			is_word = FALSE;
		s++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char const c)
{
	char	**strs;
	size_t	wordcount;
	char	**strs_ptr;

	wordcount = ft_wordcount((char *)s, c);
	strs = (char **)ft_calloc(wordcount + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (ft_wordlen((char *)s, c, strs))
	{
		strs_ptr = strs;
		while (*strs_ptr)
		{
			free(*strs_ptr);
			strs_ptr++;
		}
		free (strs);
		return (NULL);
	}
	return (strs);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**strs;

// 	strs = ft_split(" by by sayonara ", ' ');
// 	while (*strs)
// 	{
// 		printf("%s\n", *strs);
// 		strs++;
// 	}
// }
