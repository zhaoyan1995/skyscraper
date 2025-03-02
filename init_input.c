/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:48:25 by yanzhao           #+#    #+#             */
/*   Updated: 2025/03/02 23:51:48 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_digit_argv(int len_str, char *str)
{
	int	i;
	int	nb_digit;

	i = 0;
	nb_digit = 0;
	while (i < len_str)
	{
		if ((str[i] - 48) > 0 && (str[i] - 48) < 5)
		{
			i++;
			nb_digit++;
		}
		else if (str[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (nb_digit);
}

int	*generate_input(int nb_digit, char *str)
{
	int	i;
	int	j;
	int	*input;

	input = (int *)malloc(sizeof(int) * nb_digit);
	i = 0;
	j = 0;
	while (j < nb_digit)
	{
		if ((str[i] - 48) > 0 && (str[i] - 48) < 5)
		{
			input[j] = str[i] - 48;
			i++;
			j++;
		}
		else if (str[i] == ' ')
			i++;
		else
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
	}
	return (input);
}
