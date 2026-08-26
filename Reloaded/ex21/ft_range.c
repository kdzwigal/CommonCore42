/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:57:58 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/21 09:58:01 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_arr_make(int *arr, int size, int min, int max)
{
	int	i;

	i = 0;
	while (i < size && min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	while (i < size && min == max)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}

int	*ft_range(int min, int max)
{
	int	*arr;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min + 1) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	ft_arr_make(arr, (max - min + 1), min, max);
	return (arr);
}

/*#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*arr;
	int	i;

	min = 23;
	max = 100;
	arr = ft_range(min, max);
	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != '\0')
		{
			printf("===   %d\n", arr[i]);
			i++;
		}
			printf("===   %d\n", arr[i]);
	}
}*/
