/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 02:26:29 by ynenakho          #+#    #+#             */
/*   Updated: 2017/12/04 02:16:53 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_length;
	int		s2_length;
	char	*new;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new = ft_strnew(s1_length + s2_length);
	if (!new)
		return (NULL);
	while (*s1 || *s2)
		*new++ = (*s1) ? *s1++ : *s2++;
	*new = '\0';
	return (new - s1_length - s2_length);
}
