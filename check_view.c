/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:01 by yanzhao           #+#    #+#             */
/*   Updated: 2025/03/02 20:09:19 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	function(int *tab)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 1;
	while (i < 3 && j < 4)
	{
		if (tab[i] < tab[j])
		{
			result++;
			if (tab[j] == 4)
				break ;
			i++;
			j++;
		}
		else
			j++;
	}
	return (result);
}
