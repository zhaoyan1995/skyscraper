/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_overview.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:27:49 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/27 19:42:39 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	function(int *tab);
int	*ft_put_view_colup(int **tab, int line, int col);
int	*ft_put_view_coldown(int **tab, int line, int col);
int	*ft_put_view_line_left(int **tab, int line, int col);
int	*ft_put_view_line_right(int **tab, int line, int col);

void	put_overview(int **tab, int **overview)
{
	int	*view;
	int	i;	
	int	j;

	*overview = (int *)malloc(sizeof(int) * 16);
	if (overview == NULL)
		return ;
	i = 0;
	j = 0;
	view = ft_put_view_colup(tab, 0, 0);
	while (i < 4)
		(*overview)[j++] = view[i++];
	free(view);
	i = 0;
	view = ft_put_view_coldown(tab, 3, 0);
	while (i < 4)
		(*overview)[j++] = view[i++];
	free(view);
	i = 0;
	view = ft_put_view_line_left(tab, 0, 0);
	while (i < 4)
		(*overview)[j++] = view[i++];
	free(view);
	i = 0;
	view = ft_put_view_line_right(tab, 0, 3);
	while (i < 4)
		(*overview)[j++] = view[i++];
	free(view);
}

/*#include <stdio.h>

int	main(void)
{
	int	*overview;
	int	i;
	int	tab[4][4] = {{1, 2, 3, 4},
			{4, 3, 2, 1},
			{2, 4 ,1, 3},
			{3, 1, 4, 2}};

	put_overview(tab, &overview);
	i = 0;
	while (i < 16)
	{
		printf("overview[%d] = %d\n", i, overview[i]);
		i++;
	}
	free(overview);
	return (0);
}*/
