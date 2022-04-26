/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:30:24 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/24 21:41:58 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	s_len = ft_len(src);
	d_len = ft_len(dest);
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	while (src[i] && d_len + i < size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
		dest[d_len + i] = '\0';
	return (d_len + s_len);
}
