/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/09 17:27:32 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Function: get_next_line
 * -----------------------
 * Reads and returns an entire line from a given file descriptor, including 
 * the terminating '\n' character.
 *
 * Logic:
 *   - Concatenate the existing content from the static buffer to the current
 * 	   line.
 *   - Run a loop while there is no '\n' character in the line:
 *       - Read data into the buffer.
 *       - Concatenate the buffer to the current line.
 *       - Exit the loop when a '\n' is found or when no more bytes are read
 *         (indicating end of line or end of file).
 *   - Shift the buffer contents to the left, removing the part already used,
 *     and fill the remaining space with '\0'.
 *
 * Return:
 *   Returns the full line including the newline character ('\n'), 
 *   or NULL if there is nothing more to read or an error occurs.
 *
 * Notes:
 *   - buffer[0] == '\0':
 *       When the function is called after reaching the end of the file,
 *       the buffer will contain only '\0' due to the last call to 
 * 		 shift_buffer_left().
 *       Since no bytes are left to read, the buffer remains '\0' across 
 * 		 subsequent get_next_line calls.
 *
 *   - bytes_read == 0:
 *       Indicates that the read() function has reached the end of file and
 *       no more bytes were read.
 *
 *   - buffer[bytes_read] = '\0':
 *       Although the buffer always ends with a '\0' for string safety, we
 * 		 explicitly set buffer[bytes_read] = '\0' after each read to ensure the
 *		 string is properly null-terminated at the correct length.
 * 		 This ensures that the last read is properly truncated, regardless of
 * 		 the number of bytes read.
 *
 *   - shift_buffer_left(buffer):
 *       The buffer is a static array that retains unread data between function
 * 		 calls.
 *       Before returning the current line to the caller, we shift any 
 * 		 remaining data in the buffer to the beginning and fill the rest with
 * 		 '\0' to avoid data corruption.
 *
 *   - ulimit -n:
 *       This is a shell command that displays the soft limit for the number of
 *  	 open file descriptors allowed per process on the current system.
 */

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = join_buffer_to_line(buffer, line);
	while (!search_buffer_linebreak(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == 0)
		{
			shift_buffer_left(buffer);
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = join_buffer_to_line(buffer, line);
	}
	shift_buffer_left(buffer);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main (void)
{
	int	fd;
	char *str;
	//char *str1;
	//char *str2;

	fd = open("", O_RDONLY);
	while((str = get_next_line(fd))){
		printf("%s", str);
		free(str);
	}
	//str1 = get_next_line(fd);
	//str2 = get_next_line(fd);
	//printf("%s", str);
	//printf("%s", str1);
	//printf("%s", str2);
	//free(str);
	//free(str1);
	//free(str2);
	close(fd);
	//printf("%s", get_next_line(0));
} */
