/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:12:03 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/17 09:12:04 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	main(int argc, char **argv)
{
	int		fd;
	size_t	bytes_read;
	char	buffer[1024];

	if (argc == 1)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_puterr("Cannot read file.\n");
		else
		{
			bytes_read = read(fd, buffer, 1024);
			while (bytes_read > 0)
			{
				write(1, buffer, bytes_read);
				sleep(1);
				bytes_read = read(fd, buffer, 1024);
			}
			close(fd);
		}
	}
	return (0);
}
