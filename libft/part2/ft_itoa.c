/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:33:39 by seonseo           #+#    #+#             */
/*   Updated: 2023/10/31 18:59:28 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_fillnbr(char *nbr_str, int nbrlen, int n)
{
	nbr_str[nbrlen] = '\0';
	nbrlen--;
	while (0 <= nbrlen)
	{
		nbr_str[nbrlen] = n % 10;
		n /= 10;
		nbrlen--;
	}
}

static int	ft_nbrlen(int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr_str;
	int		nbrlen;

	printf("n:%d\n", n);
	nbrlen = ft_nbrlen(n);
	printf("nbrlen:%d\n", nbrlen);
	nbr_str = (char *)malloc(sizeof(char) * (nbrlen + 1));
	if (nbr_str == NULL)
		return (NULL);
	printf("%p\n", nbr_str);
	ft_fillnbr(nbr_str, nbrlen, n);
	return (nbr_str);
}
#include <stdio.h>

int	main(void)
{
	printf("\"%s\"\n", ft_itoa(14));
}
