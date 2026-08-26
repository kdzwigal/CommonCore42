/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:38:00 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/14 16:20:26 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	gnl_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

void	maino(void)
{
    char *line;
    int line_count = 1;

    printf("--- Testowanie Standard Input (fd 0) ---\n");
    printf("Wpisuj tekst poniżej. Wciśnij Ctrl+D na pustej linii (EOF), aby zakończyć.\n\n");

    // Deskryptor 0 to standardowe wejście (stdin)
    while ((line = get_next_line(0)) != NULL)
    {
        printf("[Odczytano %d]: %s", line_count, line);
        free(line);
        line_count++;
    }
    
    printf("\n--- Osiągnięto EOF (koniec czytania) ---\n");
    return ;
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*print = NULL;
	char	*full = NULL;
	int		i;

	if (argc == 1)
		gnl_puterr("File name missing.\n");
	else if (argc > 2)
		gnl_puterr("Too many arguments.\n");
	else if (strcmp(argv[1], "input") == 0)
		maino();
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			gnl_puterr("Cannot read file.\n");
		else
		{
			i = 0;
			print = get_next_line(fd);
			while (print != NULL)
			{
				printf("petla main %2d === ", ++i);
				printf("%s", print);
				full = gnl_strjoin(full, print, gnl_strlen(full), gnl_strlen(print));
				free(print);
				print = get_next_line(fd);
			}
			printf("___\n%s\n", full);
		}
		free(print);
		free(full);
		close(fd);
	}
	return (0);
}
