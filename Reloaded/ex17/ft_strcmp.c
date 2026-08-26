/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:32:25 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/05/12 16:32:32 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*#include <stdio.h>

int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "Abc";

	printf("\n\nroznica: %d\n\n\n", ft_strcmp(s1, s2));
	if ((ft_strcmp(s1, s2)) == 0)
		printf("s1 and s2 are equal: %d\n\n\n", (ft_strcmp(s1, s2)));
	else if ((ft_strcmp(s1, s2)) > 0)
		printf("s1 is greater than s2: %d\n\n\n", (ft_strcmp(s1, s2)));
	else if ((ft_strcmp(s1, s2)) < 0)
		printf("s1 is less than s2: %d\n\n\n", (ft_strcmp(s1, s2)));
}
*/
