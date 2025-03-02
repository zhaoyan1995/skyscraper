/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:56:25 by yanzhao           #+#    #+#             */
/*   Updated: 2025/03/02 23:31:55 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	generate_digit(int **tab, int line, int col, int *input);
int		ft_strlen(char *str);
int		count_digit_argv(int len_str, char *str);
int		*generate_input(int nb_digit, char *str);

int	**generate_map(void)
{
	int	i;
	int	**map;

	map = (int **)malloc(sizeof(int *) * 4);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		map[i] = (int *)malloc(sizeof(int) * 4);
		if (map[i] == NULL)
		{
			while (i >= 0)
			{
				free(map[i]);
				i--;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	**set_up_map(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	free_map(int **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	int	*input;
	int	nb_digit;
	int	len_argv;
	int	**map;

	if (argc != 2)
		write(2, "Error\n", 6);
	else
	{
		nb_digit = 0;
		len_argv = ft_strlen(argv[1]);
		nb_digit = count_digit_argv(len_argv, argv[1]);
		if (nb_digit != 16)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		input = generate_input(nb_digit, argv[1]);
		map = generate_map();
		map = set_up_map(map);
		generate_digit(map, 0, 0, input);
		free_map(map);
		free(input);
	}
	return (0);
}
