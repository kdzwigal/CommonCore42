/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:25:02 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/07/14 16:20:27 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	gnl_strlen(const char *str);

char	*gnl_strjoin(char *s1, char *s2, ssize_t s1_len, ssize_t s2_len);

char	*gnl_substr(char const *s, unsigned int start, size_t len);

char	*gnl_newstash_free(const char *src, size_t start);

ssize_t	gnl_strchr_n(char *s);

char	*read_to_stash(int fd, char *stash);

char	*extract_and_update(char **stash, ssize_t endl_index);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

#endif