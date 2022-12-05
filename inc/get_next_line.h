/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:37:25 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/05 17:38:48 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

// This is a preprocessor directive. It is checking if MAX_FD is defined. If it is not defined, it will define it as 10240.
# ifndef MAX_FD
#  define MAX_FD 10240
# endif

// This is a preprocessor directive. It is checking if BUFFER_SIZE is defined. If it is not defined, it will define it as 8.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd, char **to);
char	*gn_reader(int fd, char *read_res, char **buffer);
char	*append_line(int nl_index, char **buffer);
void	free_str(char **ptr);
/*Helpers*/
char	*gn_strdup(char *str);
size_t	gn_strlen(char *s);
int		gn_strchr(char *str, char n);
char	*gn_strjoin(char *s1, char *s2);
char	*gn_substr(char *s, unsigned int start, size_t len);
char	*append_line(int nl_index, char **buffer);
#endif
