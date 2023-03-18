/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:50:21 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/18 14:32:21 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Concatenates two strings and releases the parameters.
 * @param s1 a null-terminating string.
 * @param s2 a null-terminating string.
 * @return a new string concatenating both string params.
 */
static char *concat(char *s1, char *s2)
{
    size_t  len1;
    size_t  len2;
    char    *res;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    res = (char *) ft_calloc(len1 + len2 + 1, sizeof(char));
    ft_strlcpy(res, s1, len1);
    ft_strlcpy(res + len1, s2, len2);
    free(s1);
    free(s2);
    return res;
}

/**
 * validate the extension is correct. (it should finish in .ber)
 * @param filename The name of the file to validate.
 * @return a positive number if the filename has got the correct extension or 0 if it is incorrect.
 */
static int valid_extension(char *filename)
{
    size_t  len;

    len = ft_strlen(filename);
    return (len > 4 
        && filename[len - 4] == '.'
        && filename[len - 3] == 'b'
        && filename[len - 2] == 'e'
        && filename[len - 1] == 'r');
}

void    *sl_print_error(char *error_str)
{
    size_t  str_len;

    str_len = ft_strlen(error_str);
    write(2, error_str, str_len);
    return (0);
}

t_data  *sl_read_map(char *filename)
{
    int     fd;
    char    *line;
    char    *map;
    size_t  width;
    size_t  height;

    if (!valid_extension(filename))
        return (sl_print_error("Error\nSe ha intentado leer un fichero que no es .ber."));
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (sl_print_error("Error\nHubo un problema con la lectura del fichero."));
    line = ft_get_next_line(fd);
    width = ft_strlen(line);
    height = 0;
    map = 0;
    if (line == 0)
        return (close(fd), (t_data *) sl_print_error("Error\nEl mapa está vacío"));
    while (line && ft_strlen(line) > 0)
    {
        if (width != ft_strlen(line))
            return (close(fd), free(line), free(map), (t_data *) sl_print_error("Error\nEl mapa no es rectangular."));
        map = concat(map, line);
        line = ft_get_next_line(fd);
        height++;
    }
    return (close(fd), sl_verify_map(map, width, height));
}