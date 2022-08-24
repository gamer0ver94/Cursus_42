/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaulino <dpaulino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:03:54 by dpaulino          #+#    #+#             */
/*   Updated: 2022/05/06 14:03:54 by dpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t counter, size_t size)
{
	char	*res;

	res = malloc(size * counter);
	if (!res)
		return (NULL);
	ft_bzero(res, size * counter);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		lenght;
	int		i;
	int		j;

	i = 0;
	lenght = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * lenght + 1);
	if (!s1 || !s2 || !newstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[lenght] = '\0';
	return (newstr);
}

char	*ft_clean(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

int	verify_buffer(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
