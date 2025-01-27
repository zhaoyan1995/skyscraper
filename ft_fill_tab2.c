/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:37:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/27 19:44:46 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_solution(int *overview, int *input);
void    put_overview(int **tab, int **overview);

int	check_doublon(int **tab, int line, int col, int digit)
{
	int	i_col;
	int	j_line;

	i_col = 0;
	while (i_col < col)
	{
		if (tab[line][i_col] == digit)
			return (0);
		i_col++;
	}
	j_line = 0;
	while (j_line < line)
	{
		if (tab[j_line][col] == digit)
			return (0);
		j_line++;
	}
	return (1);
}

void	ft_put_tab(int **tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);	
		i++;
	}
	write(1, "\n", 1);
}

void	generate_digit(int **tab, int line, int col, int *input, int *nb_solution)
{
	int	digit;
	int	*overview;

	if (line == 4)
	{
		put_overview(tab, &overview);
		if (check_solution(overview, input) == 1)
		{		
			ft_put_tab(tab);
			(*nb_solution)++;
		}
		free(overview);
		return ;
	}
	digit = 1;
	while (digit <= 4)
	{
		if (check_doublon(tab, line, col, digit))
		{
			tab[line][col] = digit;
			if (col == 3)
				generate_digit(tab, line + 1, 0, input, nb_solution);
			else
				generate_digit(tab, line, col + 1, input, nb_solution);
			tab[line][col] = 0;
		}
		digit++;
	}
}
