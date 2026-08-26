/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdzwigal <kdzwigal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:02:43 by kdzwigal          #+#    #+#             */
/*   Updated: 2026/06/29 17:02:48 by kdzwigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int c);
//checks for an alphabetic character;

int		ft_isdigit(int c);
//checks for a digit (0 through 9);

int		ft_isalnum(int c);
//checks for an alphanumeric character
//it is equivalent to (isalpha(c) || isdigit(c));

int		ft_isascii(int c);
//checks whether c is a 7-bit unsigned char value
//that fits into the ASCII character set;

int		ft_isprint(int c);
//checks for any printable character including space;

size_t	ft_strlen(const char *str);
//The ft_strlen() function calculates the length of the string s,
//excluding the terminating null byte (aq\0aq)
//The ft_strlen() function returns the number of bytes in the string s.

void	*ft_memset(void *s, int c, size_t len);
//The memset() function fills the first n bytes of the memory area 
//pointed to by s with the constant byte c.
//The memset() function returns a pointer to the memory area s.

void	ft_bzero(void *s, size_t n);
//The bzero() function sets the first n bytes of the area
//starting at s to zero (bytes containing aq\0aq).

void	*ft_memcpy(void *dest, const void *src, size_t n);
//The memcpy() function copies n bytes from memory area src to memory
//area dest. The memory areas must not overlap. Use memmove(3) if the
//memory areas do overlap. The memcpy() function returns a pointer to dest.

void	*ft_memmove(void *dest, const void *src, size_t n);
//The memmove() function copies n bytes from memory area src to memory
//area dest. The memory areas may overlap: copying takes place as though
//the bytes in src are first copied into a temporary array that does not
//overlap src or dest, and the bytes are then copied from the temporary
//array to dest. The memmove() function returns a pointer to dest.

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
//The strlcpy() function copies up to size - 1 characters
//from the NUL-terminated string src to dst, NUL-terminating the result.
//The strlcpy() function return the total length of the string it tried
//to create, that means the length of src.

size_t	ft_strlcat(char *dest, const char *src, size_t size);
//The strlcat() function appends the NUL-terminated string src to the
//end of dst. It will append at most size - strlen(dst) - 1 bytes,
//NULL-terminating the result. The strlcat() function return the total
//length of the string it tried to create. For strlcat() that means the
//initial length of dst plus the length of src.

int		ft_toupper(int c);
//toupper() converts the letter c to upper case, if possible.

int		ft_tolower(int c);
//tolower() converts the letter c to lower case, if possible.

char	*ft_strchr(const char *s, int c);
//The strchr() function returns a pointer to the first occurrence of the
//character c in the string s.

char	*ft_strrchr(const char *s, int c);
//The strrchr() function returns a pointer to the last occurrence of the
//character c in the string s.

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
//The strncmp() function only compares the first (at most) n bytes of s1
//and s2. It returns an integer less than, equal to, or greater than zero
//if s1 is found, respectively, to be less than, to match, or be greater
//than s2. The strncmp() functions return an integer less than, equal to,
//or greater than zero if s1 (or the first n bytes thereof) is found,
//respectively, to be less than, to match, or be greater than s2.

void	*ft_memchr(const void *s, int c, size_t n);
//The memchr() function scans the initial n bytes of the memory area
//pointed to by s for the first instance of c. Both c and the bytes of
//the memory area pointed to by s are interpreted as unsigned char.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
//The memcmp() function returns an integer less than, equal to, or greater
//than zero if the first n bytes of s1 is found, respectively, to be less
//than, to match, or be greater than the first n bytes of s2.
//For a nonzero return value, the sign is determined by the sign of the
//difference between the first pair of bytes (interpreted as unsigned char)
//that differ in s1 and s2.

char	*ft_strnstr(const char *s1, const char *s2, size_t n);
//The strnstr() function locates the first	occurrence of the
//null-terminated string s2 in the string s1, where not more than len
//characters are searched. Characters that appear after a `\0' character
//are not searched.

int		ft_atoi(const char *str);
//The atoi() function converts initial part of string in str to integer.
//The string may begin with an arbitrary amount of white space (as
//determined by isspace(3)) followed by a single optional '+' or '-' sign.

void	*ft_calloc(size_t nmemb, size_t size);
//The calloc() function allocates memory for an array of nmemb elements of
//size bytes each and returns a pointer to the allocated memory. The memory
//is set to zero. If nmemb or size is 0, then calloc() returns either NULL,
//or a unique pointer value that can later be successfully passed to free().

char	*ft_strdup(const char *src);
//The strdup() function returns a pointer to a new string which is a
//duplicate of the string src. Memory for the new string is obtained with
//malloc(3), and can be freed with free(3).

char	*ft_substr(char const *s, unsigned int start, size_t len);
//s: The original string from which to create the substring.
//start: The starting index of the substring within ’s’.
//len: The maximum length of the substring.
//Return Value (The substring). (NULL) if the allocation fails.
//Description Allocates memory (using malloc(3)) and returns a
//substring from the string ’s’.
//The substring starts at index ’start’ and has a maximum length of ’len’.

char	*ft_strjoin(char const *s1, char const *s2);
//s1: The prefix string. s2: The suffix string. Return Value (The new string).
//(NULL) if the allocation fails.
//Description Allocates memory (using malloc(3)) and returns a new string,
//which is the result of concatenating ’s1’ and ’s2’.

char	*ft_strtrim(char const *s1, char const *set);
//s1: The string to be trimmed. set: The string containing the set of
//characters to be removed.
//Return Value (The trimmed string). (NULL) if the allocation fails.
//Description Allocates memory (using malloc(3)) and returns a copy of ’s1’ 
//with characters from ’set’ removed from the beginning and the end.

char	**ft_split(char const *s, char c);
//s: The string to be split. c: The delimiter character.
//Return Value The array of new strings resulting from the split.
//NULL if any allocation fails.
//The returned structure will be released using: 
//1) free() on each string in the array; 2) free() the array itself.
//Description Allocates memory (using malloc(3)) and returns an array of 
//strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
//Each string in the returned array is allocated independently.
//The array of pointers itself is also allocated dynamically.
//The returned array must be NULL terminated.

char	*ft_itoa(int n);
//n: The integer to convert. Return Value The string representing the integer.
//NULL if the allocation fails.
//Description Allocates memory (using malloc(3)) and returns a string 
//representing the integer received as an argument. Negative numbers must
//be handled.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//s: The string to iterate over. f: The function to apply to each character.
//Return Value The string created from the successive applications of ’f’.
//Returns NULL if the allocation fails.
//Description Applies the function f to each character of the string s, passing
//its index as the first argument and the character itself as the second. A new
//string is created (using malloc(3)) to store the results from the successive
//applications of f.

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//s: The string to iterate over. f: The function to apply to each character.
//Return Value None
//Description Applies the function ’f’ to each character of the string passed
//as argument, passing its index as the first argument. Each character is passed
//by address to ’f’ so it can be modified if necessary.

void	ft_putchar_fd(char c, int fd);
//c: The character to output. fd: The file descriptor on which to write.
//Return Value None Description Outputs the character ’c’ to the specified file
//descriptor.

void	ft_putstr_fd(char *s, int fd);
//s: The string to output. fd: The file descriptor on which to write.
//Return Value None Description Outputs the string ’s’ to the specified file
//descriptor.

void	ft_putendl_fd(char *s, int fd);
//s: The string to output. fd: The file descriptor on which to write.
//Return Value None
//Description Outputs the string ’s’ to the specified file descriptor followed 
//by a newline.

void	ft_putnbr_fd(int n, int fd);
//n: The integer to output. fd: The file descriptor on which to write.
//Return Value None Description Outputs the integer ’n’ to the specified file
//descriptor.

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content);
//content: The content to store in the new node. Return Value A pointer to the
//new node
//Description Allocates memory (using malloc(3)) and returns a new node. The
//’content’ member variable is initialized with the given parameter ’content’.
//The variable ’next’ is initialized to NULL.

void	ft_lstadd_front(t_list **lst, t_list *new);
//lst: The address of a pointer to the first node of a list.
//new: The address of a pointer to the node to be added.
//Description Adds the node ’new’ at the beginning of the list.

int		ft_lstsize(t_list *lst);
//lst: The beginning of the list. Return Value The length of the list
//Description Counts the number of nodes in the list.

t_list	*ft_lstlast(t_list *lst);
//lst: The beginning of the list. Return Value Last node of the list
//Description Returns the last node of the list.

void	ft_lstadd_back(t_list **lst, t_list *new);
//lst: The address of a pointer to the first node of a list.
//new: The address of a pointer to the node to be added.
//Description Adds the node ’new’ at the end of the list.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//lst: The node to free. del: The address of the function used to delete
//the content.
//Description Takes a node as parameter and frees its content using the function
//’del’. Free the node itself but does NOT free the next node.

void	ft_lstclear(t_list **lst, void (*del)(void *));
//lst: The address of a pointer to a node. del: The address of the function used
//to delete the content of the node. Description Deletes and frees the given 
//node and all its successors, using the function ’del’ and free(3).
//Finally, set the pointer to the list to NULL.

void	ft_lstiter(t_list *lst, void (*f)(void *));
//lst: The address of a pointer to a node. f: The address of the function to
//apply to each node’s content.
//Description Iterates through the list ’lst’ and applies the function ’f’ to
//the content of each node.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//lst: The address of a pointer to a node. f: The address of the function
//applied to each node’s content.
//del: The address of the function used to delete a node’s content if needed.
//Return Value The new list. NULL if the allocation fails.
//Description Iterates through the list ’lst’, applies the function ’f’ to each
//node’s content, and creates a new list resulting of the successive
//applications of the function ’f’. The ’del’ function is used to delete the
//content of a node if needed.

#endif
