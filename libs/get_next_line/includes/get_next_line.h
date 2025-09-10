/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:37 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/19 15:34:13 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//macros

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//libraries

# include <unistd.h>
# include <stdlib.h>

//prototype functions

char	*get_next_line(int fd);
char	*join_buffer_to_line(char *buffer, char *line);
char	*shift_buffer_left(char *buffer);
int		search_buffer_linebreak(char *buffer);
int		get_len(char *string);

#endif