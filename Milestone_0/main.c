/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:05:53 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/29 14:05:55 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	f_content(void *content)
{
	int	*value;
	
	value = (int *)content;
	if (content)
	{
		printf("=== f_content before === %d\n", *value);
		*value += 42;
		printf("=== f_content after === %d\n", *value);
	}
}

static void	*f_content1(void *content)
{
	int	*new_value;
	int	*old_value;
	
	old_value = (int *)content;
	new_value = (int *)malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = *old_value + 42;
	return (new_value);
}

static char	ft_oddstoup(unsigned int i, char c)
{
	if (i % 2 != 0 && c >= 'A' && c <= 'Z')
		c += 32;
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

static void ft_oddstoup1(unsigned int i, char *c)
{
	char	x;
	
	x = *c;
	if (i % 2 != 0 && x >= 'A' && x <= 'Z')
		*c += 32;
	if (i % 2 == 0 && x >= 'a' && x <= 'z')
		*c -= 32;
	return;
}

static void	delete_content(void *content)
{
	if (content)
	{
		free(content);
		printf("Content deleted succesfully.\n");
	}
}

void	test_ft_isalpha(void)
{
	char	a;
	char	b;
	char	c;

	a = '-';
	b = 'B';
	c = '4';
	if (ft_isalpha(a) == 1)
		printf("   %c is alpha.\n", a);
	else
		printf("   %c is not alpha.\n", a);
	if (ft_isalpha(b) == 1)
		printf("   %c is alpha.\n", b);
	else
		printf("   %c is not alpha.\n", b);
	if (ft_isalpha(c) == 1)
		printf("   %c is alpha.\n", c);
	else
		printf("   %c is not alpha.\n", c);
	return;
}

void	test_ft_isdigit(void)
{
	char	a;
	char	b;
	char	c;

	a = '-';
	b = 'B';
	c = '4';
	if (ft_isdigit(a) == 1)
		printf("   %c is digit.\n", a);
	else
		printf("   %c is not digit.\n", a);
	if (ft_isdigit(b) == 1)
		printf("   %c is digit.\n", b);
	else
		printf("   %c is not digit.\n", b);
	if (ft_isdigit(c) == 1)
		printf("   %c is digit.\n", c);
	else
		printf("   %c is not digit.\n", c);
	return;
}

void	test_ft_isalnum(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = '-';
	c = '4';
	if (ft_isalnum(a) == 1)
		printf("   %c is alnum.\n", a);
	else
		printf("   %c is not alnum.\n", a);
	if (ft_isalnum(b) == 1)
		printf("   %c is alnum.\n", b);
	else
		printf("   %c is not alnum.\n", b);
	if (ft_isalnum(c) == 1)
		printf("   %c is alnum.\n", c);
	else
		printf("   %c is not alnum.\n", c);
	return;
}

void	test_ft_isascii(void)
{
	char	a;
	char	b;
	char	c;

	a = '\0';
	b = '\n';
	c = '4';
	if (ft_isascii(a) == 1)
		printf("   %c is ascii.\n", a);
	else
		printf("   %c is not ascii.\n", a);
	if (ft_isascii(b) == 1)
		printf("   %c is ascii.\n", b);
	else
		printf("   %c is not ascii.\n", b);
	if (ft_isascii(c) == 1)
		printf("   %c is ascii.\n", c);
	else
		printf("   %c is not ascii.\n", c);
	return;
}

void	test_ft_isprint(void)
{
	char	a;
	char	b;
	char	c;

	a = '\0';
	b = 'a';
	c = '4';
	if (ft_isprint(a) == 1)
		printf("   %c is print.\n", a);
	else
		printf("   %c is not print.\n", a);
	if (ft_isprint(b) == 1)
		printf("   %c is print.\n", b);
	else
		printf("   %c is not print.\n", b);
	if (ft_isprint(c) == 1)
		printf("   %c is print.\n", c);
	else
		printf("   %c is not print.\n", c);
	return;
}

void	test_ft_strlen(void)
{
	char	*str;

	str = "0123456789";
	printf("=== %s === is that long => %ld\n\n", str, ft_strlen(str));
	str = "This is a string to test the ft_strlen.c";
	printf("=== %s === is that long => %ld\n\n", str, ft_strlen(str));
	str = "abcdefghijklmnopqrstuwvxyz";
	printf("=== %s === is that long => %ld\n\n", str, ft_strlen(str));
	return;
}

void    test_ft_memset(void)
{
	char	str[] = "This is a string to test the ft_memset.c";
	int		c;
	size_t	len;
	char	*ftmem;

	c = '+';
	len = 5;
	printf("=== %s === first %ld bytes will be filled with => %d\n\n", str, len, c);
	ftmem = (char *)ft_memset(str, c, len);
	printf("=== %s === first %ld bytes is filled with => %d\n\n", ftmem, len, c);
	c = '*';
	len = 20;
	printf("=== %s === first %ld bytes will be filled with => %d\n\n", str, len, c);
	ftmem = (char *)ft_memset(str, c, len);
	printf("=== %s === first %ld bytes is filled with => %d\n\n", ftmem, len, c);
	return;
}

void	test_ft_bzero(void)
{
	char	str[] = "This is a string to test the ft_bzero.c";
	size_t	len;

	len = 8;
	printf("=== %s === first %ld bytes will be filled with => '0'\n\n", str, len);
	ft_bzero(str, len);
	printf("=== %s === first %ld bytes is filled with => '0'\n\n", str + len, len);
	return;
}

void	test_ft_memcpy(void)
{
	char	str[] = "This is a string to test the ft_strlen.c";
	char	dest[] = "To this string ft_memcpy will copy str";
	size_t	len;

	len = 15;
	printf("dest === %s === before %ld chars was copied from => %s\n\n", dest, len, str);
	ft_memcpy(dest, str, (len * sizeof(char)));
	printf("dest === %s === before %ld chars was copied from => %s\n\n", dest, len, str);
	return;
}
void	test_ft_memmove(void)
{
	char	str[] = "abcdefghijklmnopqrstuwvxyz This is a string to test the ft_memmove.c";
	char	dest[] = "012345678901234567890123456789 To this string ft_memmove will move bytes";
	size_t	len;

	len = 15;
	printf("dest === %s === \n before %ld bytes was moved from 5 index of => %s\n\n", dest, len, dest);
	ft_memmove(dest, &dest[5], (len * sizeof(char)));
	printf("dest === %s ===  %ld bytes is moved from 5 index of => %s\n\n", dest, len, dest);
	
	len = 10;
	printf("dest === %s === before %ld bytes was moved from => %s\n\n", dest, len, str);
	ft_memmove(dest, &str[0], (len * sizeof(char)));
	printf("dest === %s ===  %ld bytes is moved from => %s\n\n", dest, len, str);
	return;
}

void    test_ft_strlcpy(void)
{
	char	src[] = "abcdefghij";
	char	dest[5];
	char	dest2[] = "0123456789";
	
	printf("\n=== SRC === %s\n", src);
	printf("=== DEST === %s\n", dest);
	printf("=== DEST2 === %s\n", dest2);
	printf("SRC LEN return from ft_strcpy DEST === %ld\n", ft_strlcpy(dest, src, sizeof(dest)));
	printf("SRC LEN return from ft_strcpy DEST2=== %ld\n", ft_strlcpy(dest2, src, sizeof(dest2)));

	printf("=== SRC after ft_strlcpy === %s\n", src);
	printf("=== DEST after ft_strlcpy === %s\n", dest);
	printf("=== DEST2 after ft_strlcpy === %s\n", dest2);
	return;
}

void    test_ft_strlcat(void)
{
	char	src[] = "abcdefghji klmnopqrst wuvxyz abcdefghjiklmnopqrstwuvxyz ";
	char	dest[100] = "0123456789";
	char	dest2[50] = "1";

	printf("=== SRC === %s\n", src);
	printf("=== DEST === %s\n", (dest));
	printf("=== DEST2 === %s\n", (dest2));
	
	printf("How much place need to connect DEST + SRC == %ld\n", ft_strlcat(dest, src, sizeof(dest)));
	
	printf("=== DEST after ===%s\n", (dest));

	
	
	printf("How much place need to connect DEST2 + SRC == %ld\n", ft_strlcat(dest2, src, sizeof(dest2)));
	printf("=== DEST2 after ===%s\n", (dest2));
	return;
}

void    test_ft_toupper(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = 'B';
	c = '4';
	printf("   %c ===> %c\n", a, ft_toupper(a));
	printf("   %c ===> %c\n", b, ft_toupper(b));
	printf("   %c ===> %c\n", c, ft_toupper(c));
	return;
}

void    test_ft_tolower(void)
{
	char	a;
	char	b;
	char	c;

	a = 'a';
	b = 'B';
	c = '4';
	printf("   %c ===> %c\n", a, ft_tolower(a));
	printf("   %c ===> %c\n", b, ft_tolower(b));
	printf("   %c ===> %c\n", c, ft_tolower(c));
	return;
}

void    test_ft_strchr(void)
{
	char	src[] = "abcdefghji klmnopqrst wuvxyz abcdefghjiklmnopqrstwuvxyz ";
	char	c;

	c = 'j';
	printf("=== SRC => %s\n", src);
	printf("=== char is => %c\n", c);
	printf("Found first occurence of '%c' here => %s\n", c, ft_strchr(src, c));
	
	c = 'b';
	printf("=== SRC => %s\n", src);
	printf("=== char is => %c\n", c);
	
	printf("Found first occurence of '%c' here => %s\n", c, ft_strchr(src, c));
	
	return;
}

void    test_ft_strrchr(void)
{
	char	src[] = "abcdefghji klmnopqrst wuvxyz abcdefghjiklmnopqrstwuvxyz ";
	char	c;

	c = 'j';
	printf("=== SRC => %s\n", src);
	printf("=== char is => %c\n", c);
	printf("Found last occurence of '%c' here => %s\n", c, ft_strrchr(src, c));
	
	c = 'b';
	printf("=== SRC => %s\n", src);
	printf("=== char is => %c\n", c);
	
	printf("Found last occurence of '%c' here => %s\n", c, ft_strrchr(src, c));
	
	return;
}

void    test_ft_strncmp(void)
{
	char	*s1;
	char	*s2;
	unsigned int	n;

	s2 = "aad";
	s1 = "asdf";
	n = 3;
	printf(" s1 = %s\n", s1);
	printf(" s2 = %s\n", s2);
	printf(" chars to compare = %d\n", n);
	printf(" Difference === %d\n", ft_strncmp(s1, s2, n));
	if ((ft_strncmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_strncmp(s1, s2, n)));
		
	s2 = "bad";
	s1 = "asdf";		
	n = 2;
	printf("\n s1 = %s\n", s1);
	printf(" s2 = %s\n", s2);
	printf(" chars to compare = %d\n", n);
	printf(" Difference === %d\n", ft_strncmp(s1, s2, n));
	if ((ft_strncmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_strncmp(s1, s2, n)));
		
	s2 = "asd";
	s1 = "asdf";		
	n = 4;
	printf("\n s1 = %s\n", s1);
	printf(" s2 = %s\n", s2);
	printf(" chars to compare = %d\n", n);
	printf(" Difference === %d\n", ft_strncmp(s1, s2, n));
	if ((ft_strncmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_strncmp(s1, s2, n)));
	else if ((ft_strncmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_strncmp(s1, s2, n)));
}

void    test_ft_memchr(void)
{
	char	*src;
	char	c;
	size_t	n;
	unsigned char	*ret;

	src = "abcdefghji klmnopqrst wuvxyz abcdefghjiklmnopqrstwuvxyz ";
	c = 'a';
	n = 12;
	ret = ft_memchr(src, c, n);
	printf("\n=== bytes to scan === %ld\n", n);
	printf("\n=== SRC === %s\n", src);
	printf("\n=== char === %c\n", c);
	printf("\n %s\n", ret);
	
	c = 'r';
	n = 14;
	ret = ft_memchr(src, c, n);
	printf("\n=== bytes to scan === %ld\n", n);
	printf("\n=== SRC === %s\n", src);
	printf("\n=== char === %c\n", c);
	printf("\n %s\n", ret);
	
	
	return;
}

void    test_ft_memcmp(void)
{
	char	*s1;
	char	*s2;
	size_t	n;

	s2 = "aad";
	s1 = "asdf";
	n = 3;
	printf("\n s1 = %s", s1);
	printf(" s2 = %s", s2);
	printf(" chars to compare = %ld", n);
	printf(" Difference === %d\n", ft_memcmp(s1, s2, n));
	if ((ft_memcmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_memcmp(s1, s2, n)));
		
	s2 = "bad";
	s1 = "asdf";		
	n = 2;
	printf("\n s1 = %s", s1);
	printf(" s2 = %s", s2);
	printf(" chars to compare = %ld", n);
	printf(" Difference === %d\n", ft_memcmp(s1, s2, n));
	if ((ft_memcmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_memcmp(s1, s2, n)));
		
	s2 = "asd";
	s1 = "asdf";		
	n = 4;
	printf("\n s1 = %s", s1);
	printf(" s2 = %s", s2);
	printf(" chars to compare = %ld", n);
	printf(" Difference === %d\n", ft_memcmp(s1, s2, n));
	if ((ft_memcmp(s1, s2, n)) == 0)
		printf(" s1 and s2 are equal: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) > 0)
		printf(" s1 is greater than s2: %d\n", (ft_memcmp(s1, s2, n)));
	else if ((ft_memcmp(s1, s2, n)) < 0)
		printf(" s1 is less than s2: %d\n", (ft_memcmp(s1, s2, n)));
}

void    test_ft_strnstr(void)
{
	char	*haystack;
	char	*needle;
	size_t	n;
	char	*ret;

	haystack = "abcdefghji klmnopqrst wuvxyz abcdefghjiklmnopqrstwuvxyz ";
	needle = "def";
	n = 12;
	ret = ft_strnstr(haystack, needle, n);
	printf("\n=== HYSTACK === %s\n", haystack);
	printf("\n=== NEEDLE === %s\n", needle);
	printf("\n %s\n", ret);
	
	needle = "wuv";
	n = 50;
	ret = ft_strnstr(haystack, needle, n);
	printf("\n=== HYSTACK === %s\n", haystack);
	printf("\n=== NEEDLE === %s\n", needle);
	printf("\n %s\n", ret);
	
	// TEST 1: Normal match
	needle = "def";
	ret = ft_strnstr(haystack, needle, 12);
	printf("Find 'def' in 12: %s\n", ret); // Expected: defghji...
	
	// TEST 2: Needle is outside 'n' limit
	needle = "wuv";
	ret = ft_strnstr(haystack, needle, 10);
	printf("Find 'wuv' in 10: %s\n", ret); // Expected: (null)
	
	// TEST 3: Partial match at the limit
	needle = "abcX";
	ret = ft_strnstr(haystack, needle, 3);
	printf("Find 'abcX' in 3: %s\n", ret); // Expected: (null)
	
	// TEST 4: Empty needle
	needle = "";
	ret = ft_strnstr(haystack, needle, 5);
	printf("Find '' in 5: %s\n", ret); // Expected: abcdefghji...
	
	
	return;
}

void    test_ft_atoi(void)
{
	char	*alph;
	int	i;

	alph = "     -2147483648";
	i = ft_atoi(alph);
	printf("\n=== ALPH === %s\n", alph);
	printf("=== INT === %d\n", i);

	alph = "     -2147483649";
	i = ft_atoi(alph);
	printf("\n=== ALPH === %s\n", alph);
	printf("=== INT === %d\n", i);

	alph = "   -  -1090234";
	i = ft_atoi(alph);
	printf("\n=== ALPH (should be 0) === %s\n", alph);
	printf("=== INT === %d\n", i);

	alph = "     -- 100234";
	i = ft_atoi(alph);
	printf("\n=== ALPH (should be 0) === %s\n", alph);
	printf("=== INT === %d\n", i);

	alph = "     -+1234";
	i = ft_atoi(alph);
	printf("\n=== ALPH (should be 0) === %s\n", alph);
	printf("=== INT === %d\n", i);

	alph = "+1024";
	i = ft_atoi(alph);
	printf("\n=== ALPH === %s\n", alph);
	printf("=== INT === %d\n", i);

	return;
}

int	test_ft_calloc(void)
{
	char	*arr;
	size_t	nmemb;
	size_t	size;
	size_t	i;

	i = 0;
	nmemb = 28;
	size = 4;
	printf("\n=== NMEMB === %zu\n", nmemb);
	printf("\n=== SIZE === %zu\n", size);
	arr = ft_calloc(nmemb, size);
	
	if (!arr)
	{
		printf("Allocation failed!\n");
		return (1);
	}
	printf("\n=== Checking Memory Blocks ===\n");
	i = 0;
	while (i < 10)
	{
		printf("Byte %zu: %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

void	test_ft_strdup(void)
{
	char	str[100] = "This is string to be copied.";
	char	*dest;

	printf("STR source => %s\n", str);
	dest = ft_strdup(str);
	printf("Copied to DEST = %s\n", dest);
	free(dest);
	return;
}

void	test_ft_substr(void)
{
	char	str[100] = "This string is the source of the all problems ;)";
	char	*dest;
	size_t	len;
	unsigned int	start;

	len = 11;
	start = 2;
	dest = ft_substr(str, start, len);
	printf("\n=== STRING => %s\n", str);
	printf("\n=== start index => %d\n", start);
	printf("\n=== lenght of substr => %ld\n", len);
	
	printf("\n=== Substr => %s\n", dest);
	free(dest);
	return;
}

void	test_ft_strjoin(void)
{
	char	str1[100] = "|This string is the prefix.|";
	char	str2[100] = "|This string is the suffix.|";
	char	*dest;

	printf("\n=== STRING 1 === %s\n", str1);
	printf("\n=== STRING 2 === %s\n", str2);
	dest = ft_strjoin(str1, str2);
	printf("\n=== DEST === %s\n", dest);
	free(dest);
	return;
}

void	test_ft_strtrim(void)
{
	char	str[100] = "|This string should be free, without | and dot.|";
	char	trim[100] = "|.";
	char	*dest;

	printf("\n=== STRING === %s\n", str);
	printf("\n=== TRIMS === %s\n", trim);
	dest = ft_strtrim(str, trim);
	printf("\n=== DEST === %s\n", dest);
	free(dest);
	return;
}

void	test_ft_split(void)
{
	char	str[100] = "This string should be split to words";
	char	delim;
	char	**arr;
	int		i;

	delim = ' ';
	i = 0;
	printf("\n=== STRING === =>%s<=\n", str);
	printf("\n=== DELIMITER === =>%c<=\n", delim);
	arr = ft_split(str, delim);
	while (arr[i] != NULL)
	{
		printf("\n=== %d ELEMENT OF THE ARRAY === %s\n", i, arr[i]);
		i++;
	}
	printf("\n=== %d THE LAST ONE === %p\n", i, arr[i]);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return;
}

void	test_ft_itoa(void)
{
	char	*alph;
	int	nb;

	nb = 234567890;
	alph = ft_itoa(nb);
	
	printf("\n==== AS INT === %d\n", nb);
	printf("==== AS STR === %s\n", alph);
	
	nb = -234567890;
	alph = ft_itoa(nb);
	
	printf("\n==== AS INT === %d\n", nb);
	printf("==== AS STR === %s\n", alph);
	free(alph);
	return;
}

void	test_ft_strmapi(void)
{
	char	str1[100] = "|This string is to be modified.|";
	char	*dest;

	printf("\n=== STRING 1 === %s\n", str1);
	dest = ft_strmapi(str1, &ft_oddstoup);
	printf("\n=== DEST === %s\n", dest);
	free(dest);
	return;
}

void	test_ft_striteri(void)
{
	char	str1[100] = "| This string is to be modified.|";

	printf("\n=== STRING BEFORE === %s\n", str1);
	
	ft_striteri(str1, &ft_oddstoup1);
	
	printf("\n=== STRING AFTER === %s\n", str1);
	return;
}

void	test_ft_putchar_fd(void)
{
	char	str1[100] = "| This string is to be written by ft_putchar_fd.c.|";
	size_t	i;

	i = 0;
	printf("\n=== STRING BEFORE === %s\n", str1);
	printf("\n=== ft_putstr_fd === ");
	fflush(stdout);
	while (str1[i])
	{
		ft_putchar_fd(str1[i], 1);
		i++;
		usleep(20000);
	}
	return;
}

void	test_ft_putstr_fd(void)
{
	char	str1[100] = "| This string is to be written by ft_putstr_fd.c.|";

	printf("\n=== STRING BEFORE === %s\n", str1);
	printf("\n=== ft_putstr_fd === ");
	fflush(stdout);
	ft_putstr_fd(str1, 1);
	return;
}

void	test_ft_putendl_fd(void)
{
	char	str1[100] = "| This string is to be written by ft_putendl_fd.c.|";

	printf("\n=== STRING BEFORE === %s\n", str1);
	printf("\n=== ft_putstr_fd === ");
	fflush(stdout);
	ft_putendl_fd(str1, 1);
	return;
}

void	test_ft_putnbr_fd(void)
{
	int	n;

	n = -1203456789;
	printf("\n=== INT === %d\n", n);
	printf("\n=== ft_putnbr_fd.c === ");
	fflush(stdout);
	
	
	ft_putnbr_fd(n, 1);
	return;
}

int	test_ft_lstnew(void)
{
	t_list	*node;
	char	*cont = "test string";

	printf("\n=== cont === %s\n", cont);
	node = ft_lstnew(cont);
	if (!node)
		return (1);
	printf("=== node->content === %s\n", (char *)node->content);
	if (node->next == NULL)
		printf("=== node->next === %p\n", node->next);
	free(node);
	return (0);
}

int	test_ft_lstadd_front(void)
{
	t_list	*tmp;
	t_list	*node;
	
	t_list	*next_node;
	int		*value;
	int		i;

	tmp = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_front(&tmp, node);
		i++;
	}
	
	t_list *current = tmp;
	while (current != NULL)
	{
		printf("=== current->content === %d\n", *(int *)(current->content));
		current = current->next;
	}
	
	current = tmp;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	return (0);
}

int	test_ft_lstsize(void)
{
	t_list	*head;
	t_list	*node;
	
	t_list	*next_node;
	int		*value;
	int		i;

	head = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_front(&head, node);
		printf("=== COUNTED BY ft_lstsize.c while adding lstnew up to 10 === %d\n", ft_lstsize(head));
		i++;
	}
	
	t_list *current = head;
	while (current != NULL)
	{
		printf("=== current->content (added front) === %d\n", *(int *)(current->content));
		current = current->next;
	}
	printf("=== COUNTED BY ft_lstsize.c === %d\n", ft_lstsize(head));
	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	return (0);
}

int	test_ft_lstlast(void)
{
	t_list	*head;
	t_list	*node;
	
	t_list	*next_node;
	int		*value;
	int		i;

	head = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_front(&head, node);
		i++;
	}
	
	t_list *current = head;
	current = head;
	printf("=== content of the last element in the list  === %d\n", *(int *)(ft_lstlast(current)->content));
	current = head;
	while (current != NULL)
	{
		printf("=== list iterated from element first to last (added front )=== %d\n", *(int *)current->content);
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	return (0);
}

int	test_ft_lstadd_back(void)
{
	t_list	*tmp;
	t_list	*node;
	
	t_list	*next_node;
	int		*value;
	int		i;

	tmp = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_back(&tmp, node);
		i++;
	}
	
	t_list *current = tmp;
	while (current != NULL)
	{
		printf("=== current->content === %d\n", *(int *)(current->content));
		current = current->next;
	}
	
	current = tmp;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	return (0);
}

int	test_ft_lstdelone(void)
{
	t_list	*node;
	int		*value;

	value = (int *)malloc(sizeof(int));
	if (!value)
		return (1);
	*value = 42;
	node = ft_lstnew((void *)value);
	if (!node)
	{
		free(value);
		return (1);
	}
	printf("Value in content before del: %d\n", *(int *)(node->content));
	ft_lstdelone(node, delete_content);
	return (0);
}

int	test_ft_lstclear(void)
{
	t_list	*tmp;
	t_list	*node;
	
	//t_list	*next_node;
	int		*value;
	int		i;

	tmp = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_back(&tmp, node);
		i++;
	}
	
	t_list *current = tmp;
	while (current != NULL)
	{
		printf("=== list (added back) current->content === %d\n", *(int *)(current->content));
		current = current->next;
	}
	current = tmp;
	ft_lstclear(&current, delete_content);
	return (0);
}

int	test_ft_lstiter(void)
{
	t_list	*tmp;
	t_list	*node;
	
	int		*value;
	int		i;

	tmp = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value)
			return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node)
		{
			free(value);
			return (1);
		}
		ft_lstadd_back(&tmp, node);
		i++;
	}
	
	t_list *current = tmp;
	while (current != NULL)
	{
		printf("=== check current->content === %d\n", *(int *)(current->content));
		current = current->next;
	}
	current = tmp;
	ft_lstiter(current, f_content);
	return (0);
}

int	test_ft_lstmap(void)
{
	t_list	*tmp;
	t_list	*node;
	t_list	*mapped_list;
	int		*value;
	int		i;

	tmp = NULL;
	i = 1;
	while (i <= 10)
	{
		value = (int *)malloc(sizeof(int));
		if (!value) return (1);
		*value = i;
		node = ft_lstnew((void *)value);
		if (!node) { free(value); return (1); }
		ft_lstadd_back(&tmp, node);
		i++;
	}
	
	t_list *current = tmp;
	printf("=== ORiGINAL LIST ===\n");
	while (current != NULL)
	{
		printf("content: %d\n", *(int *)(current->content));
		current = current->next;
	}
	
	mapped_list = ft_lstmap(tmp, f_content1, delete_content);
	
	current = mapped_list;
	printf("=== NEW LIST (mapped) ===\n");
	while (current != NULL)
	{
		printf("content: %d\n", *(int *)(current->content));
		current = current->next;
	}
	current = tmp;
	printf("=== ORiGINAL LIST again ===\n");
	while (current != NULL)
	{
		printf("content: %d\n", *(int *)(current->content));
		current = current->next;
	}

	ft_lstclear(&tmp, delete_content);
	ft_lstclear(&mapped_list, delete_content);
	return (0);
}

int main(void)
{
	int choice = -1;

	while (choice != 0)
	{
		printf("\n\n====================================================================\n");
		printf("                     MENU TESTOWE LIBFT\n");
		printf("====================================================================\n");
		printf("  1. isalpha      12. strlcat      23. strdup       34. putnbr_fd\n");
		printf("  2. isdigit      13. toupper      24. substr       35. lstnew\n");
		printf("  3. isalnum      14. tolower      25. strjoin      36. lstadd_front\n");
		printf("  4. isascii      15. strchr       26. strtrim      37. lstsize\n");
		printf("  5. isprint      16. strrchr      27. split        38. lstlast\n");
		printf("  6. strlen       17. strncmp      28. itoa         39. lstadd_back\n");
		printf("  7. memset       18. memchr       29. strmapi      40. lstdelone\n");
		printf("  8. bzero        19. memcmp       30. striteri     41. lstclear\n");
		printf("  9. memcpy       20. strnstr      31. putchar_fd   42. lstiter\n");
		printf(" 10. memmove      21. atoi         32. putstr_fd    43. lstmap\n");
		printf(" 11. strlcpy      22. calloc       33. putendl_fd    0. WYJSCIE\n");
		printf("====================================================================\n");
		printf("Wybierz opcje: ");

		if (scanf("%d", &choice) != 1)
		{
			printf("Bledne wejscie! Wpisz liczbe od 0 do 43.\n");
			while (getchar() != '\n'); 
			continue;
		}

		printf("\n\n\n");

		switch (choice)
		{
			case 1: test_ft_isalpha(); break;
			case 2: test_ft_isdigit(); break;
			case 3: test_ft_isalnum(); break;
			case 4: test_ft_isascii(); break;
			case 5: test_ft_isprint(); break;
			case 6: test_ft_strlen(); break;
			case 7: test_ft_memset(); break;
			case 8: test_ft_bzero(); break;
			case 9: test_ft_memcpy(); break;
			case 10: test_ft_memmove(); break;
			case 11: test_ft_strlcpy(); break;
			case 12: test_ft_strlcat(); break;
			case 13: test_ft_toupper(); break;
			case 14: test_ft_tolower(); break;
			case 15: test_ft_strchr(); break;
			case 16: test_ft_strrchr(); break;
			case 17: test_ft_strncmp(); break;
			case 18: test_ft_memchr(); break;
			case 19: test_ft_memcmp(); break;
			case 20: test_ft_strnstr(); break;
			case 21: test_ft_atoi(); break;
			case 22: test_ft_calloc(); break;
			case 23: test_ft_strdup(); break;
			case 24: test_ft_substr(); break;
			case 25: test_ft_strjoin(); break;
			case 26: test_ft_strtrim(); break;
			case 27: test_ft_split(); break;
			case 28: test_ft_itoa(); break;
			case 29: test_ft_strmapi(); break;
			case 30: test_ft_striteri(); break;
			case 31: test_ft_putchar_fd(); break;
			case 32: test_ft_putstr_fd(); break;
			case 33: test_ft_putendl_fd(); break;
			case 34: test_ft_putnbr_fd(); break;
			case 35: test_ft_lstnew(); break;
			case 36: test_ft_lstadd_front(); break;
			case 37: test_ft_lstsize(); break;
			case 38: test_ft_lstlast(); break;
			case 39: test_ft_lstadd_back(); break;
			case 40: test_ft_lstdelone(); break;
			case 41: test_ft_lstclear(); break;
			case 42: test_ft_lstiter(); break;
			case 43: test_ft_lstmap(); break;
			case 0:
				printf("Koniec testow. Powodzenia!\n");
				break;
			default:
				printf("Nieznana opcja. Wybierz numer z menu.\n");
				break;
		}
	}
	return (0);
}
