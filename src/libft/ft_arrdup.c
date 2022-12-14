/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:35:40 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/20 18:23:37 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (!str)
		return (NULL);
	while (arr[i])
	{
		str[i] = ft_strdup(arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
