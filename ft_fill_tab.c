/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:37:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/03/02 19:53:33 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_solution(int *overview, int *input);
void	put_overview(int **tab, int **overview);

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

void	ft_print_digit(int digit)
{
	char	c;

	c = digit + 48;
	write(1, &c, 1);
	write(1, " ", 1);
}

int	ft_put_tab(int **tab, int *input, int nb_solutions)
{
	int		i;
	int		j;
	int		*overview;

	put_overview(tab, &overview);
	if (check_solution(overview, input) != 1 || nb_solutions == 1)
	{
		free(overview);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			ft_print_digit(tab[i][j++]);
		write(1, "\n", 1);
		i++;
	}
	free(overview);
	return (1);
}

void	ft_print_err_msg(int nb_try, int nb_solutions)
{
	if (nb_try == 576 && nb_solutions == 0)
		write(2, "Error\n", 6);
}

void	generate_digit(int **tab, int line, int col, int *input)
{
	int			digit;
	static int	nb_solutions = 0;
	static int	nb_try = 0;

	if (line == 4)
	{
		if (ft_put_tab(tab, input, nb_solutions) == 1)
			nb_solutions++;
		nb_try++;
		ft_print_err_msg(nb_try, nb_solutions);
		return ;
	}
	digit = 1;
	while (digit <= 4)
	{
		if (check_doublon(tab, line, col, digit))
		{
			tab[line][col] = digit;
			if (col == 3)
				generate_digit(tab, line + 1, 0, input);
			else
				generate_digit(tab, line, col + 1, input);
		}
		digit++;
	}
}
