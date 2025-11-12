/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:22:26 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 20:22:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup(const char *str)
{
    char *new_str;
    unsigned int i;

    i = 0;
    if (!str)
        return (NULL);
    new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
    if (!new_str)
        return (NULL);
    while (str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (*(str + i) != '\0')
        i++;
    return (i);
}
void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t i;
    size_t new_len;

    i = 0;
    if (size && nmemb > (size_t)-1 / size)
        return (0);
    new_len = nmemb * size;
    ptr = malloc(new_len);
    if (!ptr)
        return (NULL);
    while (i < new_len)
    {
        ((char *)ptr)[i] = '\0';
        i++;
    }
    return (ptr);
}

char *ft_strjoin_gnl(char const *s1, char const *s2)
{
    char *new_str;
    size_t len_s1;
    size_t len_s2;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!s1 && !s2)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    new_str = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
    if (!new_str)
        return (NULL);
    while (s1[j])
        new_str[i++] = s1[j++];
    j = 0;
    while (s2[j])
        new_str[i++] = s2[j++];
    return (new_str);
}
char *ft_substr(char const *str, unsigned int start, size_t len)
{
    char *new_str;
    unsigned int i;
    unsigned int str_len;

    i = 0;
    str_len = ft_strlen(str);
    if (!str || start > str_len)
    {
        new_str = ft_strdup("");
        return (new_str);
    }
    if (len > str_len - start)
        len = str_len - start;
    new_str = ft_calloc(len + 1, sizeof(char));
    if (!new_str)
        return (NULL);
    while (i < len && str[start] != '\0')
    {
        new_str[i] = str[start];
        i++;
        start++;
    }
    return (new_str);
}
