/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:58 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/22 20:12:42 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Helper Functions
 * ----------------
 * This file contains utility functions used by get_next_line to manage strings
 * and buffers more effectively.
 *
 * Functions:
 *
 * char	*join_buffer_to_line(char *buffer, char *line);
 *   - Allocates sufficient memory to join 'line' and 'buffer'.
 *   - Copies the contents of 'line' followed by 'buffer' into the new memory.
 *   - Frees the original 'line' if necessary.
 *   - Returns the newly allocated concatenated string, or NULL on failure.
 *
 * int	search_buffer_linebreak(char *buffer);
 *   - Scans the buffer for a newline character ('\n').
 *   - Returns 1 if a newline is found, 0 otherwise.
 *
 * char	*shift_buffer_left(char *buffer);
 *   - Moves the content that comes after the first '\n' in the buffer
 *     to the beginning of the buffer.
 *   - Fills the remaining buffer space with '\0'.
 *   - This preserves any unread data between get_next_line calls.
 *   - A pointer to the updated buffer containing the remaining characters
 *     after the line break, ready for the next read cycle.
 * 
 * int  get_len(char *string);
 *   - Counts the number of bytes in the string up to the first occurrence 
 *     of '\0' or '\n'.
 *   - If a '\n' is found, it includes the '\n' in the count to ensure the 
 *     returned line includes it.
 *   - Includes a safety check: if (string == NULL), the function returns 0.
 *     This handles cases where the input line is NULL on the first function 
 * 	   call.
 *	 - Returns he length of the string segment to be processed or 0 if the 
 *	   input is NULL.
 */

char	*shift_buffer_left(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
	return (buffer);
}

char	*join_buffer_to_line(char *buffer, char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * (get_len(line) + get_len(buffer) + 1));
	if (!new_line)
		return (free (line), NULL);
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i + j < (get_len(line) + get_len(buffer)))
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	new_line[i + j] = '\0';
	free(line);
	if (!new_line)
		return (free(new_line), NULL);
	return (new_line);
}

int	search_buffer_linebreak(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_len(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}
