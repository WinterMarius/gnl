# GetNextLine - Reading a Line from a File Descriptor

GetNextLine is a project that allows you to read from a file descriptor, line by line.

### Mandatory Part

#### Function Name
get_next_line

#### Prototype
`char *get_next_line(int fd);`

#### Parameters
`fd`: The file descriptor to read from

#### Return Value
- Read line: correct behavior
- NULL: there is nothing else to read, or an error occurred

#### External Functions
read, malloc, free

### Procedure
Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time. Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL. 

To compile the mandatory part, use: 
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`

## Bonus Part

- Developing `get_next_line()` using only one static variable
- Managing multiple file descriptors at the same time with `get_next_line()`

To compile the bonus part, use: 
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c`

