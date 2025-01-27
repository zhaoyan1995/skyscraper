/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_views.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:27:49 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/26 22:12:41 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	function(int *tab);

int	*ft_put_view_colup(int **tab, int line, int col)
{
	int	*tab3;
	int	tab2[4];
	int	x;
	int	y;

	y = 0;
	tab3 = (int *)malloc(sizeof(int) * 4);
	if (tab == NULL)
		return (NULL);
	while (col < 4)
	{
		line = 0;
		x = 0;
		while (line < 4 && x < 4)
			tab2[x++] = tab[line++][col];
		tab3[y++] = function(tab2);
		col++;
	}
	return (tab3);
}

int	*ft_put_view_coldown(int **tab, int line, int col)
{
	int	*tab3;
	int	tab2[4];
	int	x;
	int	y;

	y = 0;
	tab3 = (int *)malloc(sizeof(int) * 4);
	if (tab == NULL)
		return (NULL);
	while (col < 4)
	{
		line = 3;
		x = 0;
		while (line >= 0 && x < 4)
			tab2[x++] = tab[line--][col];
		tab3[y++] = function(tab2);
		col++;
	}
	return (tab3);
}

int	*ft_put_view_line_left(int **tab, int line, int col)
{
	int	*tab3;
	int	tab2[4];
	int	x;
	int	y;

	y = 0;
	tab3 = (int *)malloc(sizeof(int) * 4);
	if (tab == NULL)
		return (NULL);
	while (line < 4)
	{
		col = 0;
		x = 0;
		while (col < 4 && x < 4)
			tab2[x++] = tab[line][col++];
		tab3[y++] = function(tab2);
		line++;
	}
	return (tab3);
}

int	*ft_put_view_line_right(int **tab, int line, int col)
{
	int	*tab3;
	int	tab2[4];
	int	x;
	int	y;

	y = 0;
	tab3 = (int *)malloc(sizeof(int) * 4);
	if (tab == NULL)
		return (NULL);
	while (line < 4)
	{
		col = 3;
		x = 0;
		while (col >= 0 && x < 4)
			tab2[x++] = tab[line][col--];
		tab3[y++] = function(tab2);
		line++;
	}
	return (tab3);
}
