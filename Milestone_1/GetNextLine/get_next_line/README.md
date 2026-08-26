*This project has been created as part of the 42 curriculum by kdzwigal.*

# get_next_line

## Description
The get_next_line project introduces a highly useful function in C that reads a text file pointed to by a file descriptor, one line at a time. The main goal is to handle dynamic memory allocation, file descriptors, and static variables. Repeated calls to the function allow sequential reading until the end of the file is reached.

## Algorithm
The core challenge of this project revolves around low-level memory management and precise pointer manipulation. Since the read system call fetches data in chunks defined by the BUFFER_SIZE macro, the algorithm must cleanly preserve any excess characters read past a newline character.

To achieve this, the implementation relies on a static variable to maintain the residual data across multiple function calls. The algorithm proceeds as follows:
1. Read from the file descriptor into a temporary buffer until a newline character or the end-of-file is encountered.
2. Dynamically concatenate the newly read chunk to the data accumulated in the static buffer.
3. Once a newline is found, carefully extract the exact string constituting the complete line.
4. Update the static variable to hold only the remaining characters located after the extracted newline.

This approach ensures safe memory usage and prevents memory leaks, with all temporary buffers strictly freed after execution.

## Instructions
To use this function in your code, include the header file and compile the source files alongside your main program. You must define the buffer size at compile time.

Compilation example:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

## Resources
- Linux manual pages: read(2), malloc(3), free(3)
- C programming guides on static variables and dynamic memory management
- AI Usage: Generative AI was utilized to draft and structure this documentation file, ensuring clarity and compliance with the requested project format.

# get_next_line (Bonus)

## Description
The bonus part of the get_next_line project expands upon the mandatory requirements by adding the capability to manage multiple file descriptors simultaneously. This means the function can read from different files or streams sequentially or interchangeably without losing track of the individual reading state for each specific file descriptor.

## Algorithm
To achieve the bonus requirements while adhering to the strict constraint of using only a single static variable, the implementation relies on a broader memory structure. This is accomplished by utilizing a static array of pointers (indexed by the file descriptor, up to the system's maximum open files limit), or a static pointer to a dynamically allocated linked list.

The algorithm follows these core principles:
1. Identify the file descriptor passed to the function and locate its corresponding buffer within the static structure.
2. Read from the specific file descriptor into a temporary buffer until a newline or end-of-file is found, concatenating the newly read chunk to the fd-specific static buffer.
3. Once a newline is found, carefully extract the exact string constituting the complete line.
4. Update the specific static buffer for that fd to hold only the remaining characters located after the extracted newline.
5. Ensure strict memory isolation—if a file descriptor reaches EOF or encounters an error, its specific buffer is fully freed without disrupting the reading states or memory of other active file descriptors.

## Instructions
To use the bonus version in your code, include the bonus header file and compile the bonus source files alongside your main program. You must define the buffer size at compile time.

Compilation example:

    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c

## Resources
- Linux manual pages: read(2), malloc(3), free(3)
- C programming guides on advanced static variables, pointer arrays, and memory management for multiple I/O streams
- AI Usage: Generative AI was utilized to draft and structure this documentation file, ensuring clarity and compliance with the requested project format.
