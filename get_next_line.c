/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:22:30 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 02:51:33 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *bff;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// printf("entrei na gnl\n");
	if(!bff)
		bff = ft_calloc(1, sizeof(char)); //APAGAR 1 
	bff = read_bff(fd, bff);
	if(!bff)
		return(NULL);
	line = pull_line(&bff);
	if(!line)
		return (NULL);
	// printf("gnl -> bff: %s\n", bff); //APAGAR 2
	// printf("RETORNO DA LINHA: %s\n", line); //APAGAR 3
	return (line);
}

// char *read_bff(int fd, char *bff)
// {
//     char *temp_bff;
//     char *concat_bff;
//     ssize_t bt_read;

//     // int i; // APAGAR 1
//     // i = 0; // APAGAR 2
//     // printf("entrei na read\n"); //APAGAR 3
//     bt_read = BUFFER_SIZE;
//     temp_bff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if(!temp_bff)
// 		return(free_bff(&bff, NULL));
//     // printf("temp_bff: %s\n", temp_bff); // APAGAR 4
//     // printf("passei do temp_bff\n"); // APAGAR 5
//     while (!ft_strchr(bff, '\n') && bt_read != 0)
//     {
//         // printf("entrei na laço\n"); // APAGAR 6
//         bt_read = read(fd, temp_bff, BUFFER_SIZE);
// 		if(bt_read < 0)
// 			return (free_bff(&bff, &temp_bff));
// 		// if(bt_read == 0) // Apagar 7
// 		// 	break; // APAGAR 8
//         // printf("bt_read_loop %d: %zd\n", i++, bt_read); // APAGAR 9
//         temp_bff[bt_read] = '\0';
//         concat_bff = ft_strjoin_gnl(bff, temp_bff);
// 		if(!concat_bff)
// 			return (free_bff(&bff, &temp_bff));
//         free_bff(&bff, NULL);
//         bff = concat_bff;
//     }
// 	free_bff(&temp_bff, NULL);
// 	if((bff[0] == '\0' || !bff) && bt_read == 0)
// 		return(free_bff(&bff, NULL));
//     return (bff);
// }

char *read_bff(int fd, char *bff)
{
    char *temp_bff;
    char *concat_bff;
    ssize_t bt_read;

    bt_read = BUFFER_SIZE;
    temp_bff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!temp_bff)
		return(free_bff(&bff, NULL));
    while (!ft_strchr(bff, '\n') && bt_read != 0)
    {
        bt_read = read(fd, temp_bff, BUFFER_SIZE);
		if(bt_read < 0)
			return (free_bff(&bff, &temp_bff));
        temp_bff[bt_read] = '\0';
        concat_bff = ft_strjoin_gnl(bff, temp_bff);
		if(!concat_bff)
			return (free_bff(&bff, &temp_bff));
        free_bff(&bff, NULL);
        bff = concat_bff;
    }
	free_bff(&temp_bff, NULL);
	if((bff[0] == '\0' || !bff) && bt_read == 0)
		return(free_bff(&bff, NULL));
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
        free_bff(bff, NULL);
        *bff = temp_bff;
    }
    else
    {
        line = ft_strdup(*bff);
        free_bff(bff, NULL);
    }
    return (line);
}

char *free_bff(char **buffer, char **temp_bff)
{
    if (buffer && *buffer)
    {
        free(*buffer);
        *buffer = NULL;
    }
    if (temp_bff && *temp_bff)
    {
        free(*temp_bff);
        *temp_bff = NULL;
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
