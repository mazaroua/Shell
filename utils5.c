/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <mazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:26:11 by mazaroua          #+#    #+#             */
/*   Updated: 2023/05/06 17:18:32 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*ptr;

	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	ptr = (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			ptr = (char *) str + i;
		i++;
	}
	return (ptr);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > -1)
		free(str[i--]);
	free(str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = -1;
	j = ft_strlen(s1);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	i = -1;
	while (s2[++i])
		new[j + i] = s2[i];
	new[j + i] = '\0';
	// free(s1);
	return (new);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}