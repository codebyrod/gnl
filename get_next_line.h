/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:22:33 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 20:22:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif /* BUFFER_SIZE */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char *read_bff(int fd, char *bff);
char *pull_line(char **bff);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_substr(const char *s, unsigned int start, size_t len);
char *free_bff(char **bff, char **read_buf);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strjoin_gnl(const char *s1, const char *s2);
char *ft_strdup(const char *s1);

#endif
