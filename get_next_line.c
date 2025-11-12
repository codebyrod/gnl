/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:22:30 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 20:22:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *bff;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bff = read_bff(fd, bff);
    printf("gnl -> bff: %s\n", bff);
    return (bff);
}

char *read_bff(int fd, char *bff)
{
    char *temp_bff;
    char *concat_bff;
    ssize_t bt_read;

    int i; // APAGAR
    i = 0; // APAGAR

    printf("entrei na read\n");

    bt_read = BUFFER_SIZE;
    temp_bff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

    printf("temp_buffe: %s\n", temp_bff);
    while (!ft_strchr(bff, '\n') && bt_read != 0)
    {
        printf("entrei na laço\n");
        bt_read = read(fd, temp_bff, BUFFER_SIZE);
        printf("bt_read_loop %d: %d\n", i++, bt_read); // APAGAR
        temp_bff[bt_read] = '\0';
        concat_bff = ft_strjoin_gnl(bff, temp_bff);
        // dá free na bff;
        bff = concat_bff;
    }
    return (bff);
}

char *pull_line(char **bff)
{
    char *temp_bff;
    char *line;
    size_t len;

    if (ft_strchr(*bff, '\n'))
    {
        len = ft_strchr(*bff, '\n') - *bff + 1;
        line = ft_substr(*bff, 0, len);
        temp_bff = ft_strdup(*bff + len);
        free_buffer(bff, NULL);
        *bff = temp_bff;
    }
    else
    {
        line = ft_strdup(*bff);
        free_buffer(bff, NULL);
    }
    return (line);
}

char *free_buffer(char **buffer, char **read_buf)
{
    if (buffer && *buffer)
    {
        free(*buffer);
        *buffer = NULL;
    }
    if (read_buf && *read_buf)
    {
        free(*read_buf);
        *read_buf = NULL;
    }
    return (NULL);
}

char *ft_strchr(const char *str, int c)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == (char)c)
            return ((char *)str + i);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)str + i);
    return (0);
}
