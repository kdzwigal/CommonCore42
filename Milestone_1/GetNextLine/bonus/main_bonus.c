/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:38:00 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/14 17:08:43 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	gnl_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*print1;
	char	*full1 = NULL;
	char	*print2;
	char	*full2 = NULL;
	int		i;

	if (argc == 1 || argc == 2)
		gnl_puterr("File name missing.\n");
	else if (argc > 3)
		gnl_puterr("Too many arguments.\n");
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			gnl_puterr("Cannot read file.\n");
		fd2 = open(argv[2], O_RDONLY);
		if (fd2 == -1)
			gnl_puterr("Cannot read file.\n");
		else
		{
			i = 0;
			print1 = get_next_line(fd1);
			print2 = get_next_line(fd2);
			printf("\n");
			while (print1 != NULL || print2 != NULL)
			{
				printf("=== petla main %2d ==============================\n\n", ++i);
				printf("%s->>   %s\n", argv[1], print1);
				full1 = gnl_strjoin(full1, print1, gnl_strlen(full1), gnl_strlen(print1));
				free(print1);
				print1 = get_next_line(fd1);

				printf("%s->>   %s\n\n", argv[2], print2);
				full2 = gnl_strjoin(full2, print2, gnl_strlen(full2), gnl_strlen(print2));
				free(print2);
				print2 = get_next_line(fd2);
			}
			printf("\n%s\n", full1);
			printf("\n%s\n", full2);
			free(print1);
			free(print2);
			free(full1);
			free(full2);
		}
		close(fd1);
		close(fd2);
	}
	return (0);
}
