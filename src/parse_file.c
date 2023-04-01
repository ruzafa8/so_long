/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:50:21 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/04/01 18:48:35 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Function that get next line without the breakline at the end,
 * unless it only has got the breakline.
 * @param fd the file to read.
 * @returns the line without the \\n at the end.
 */
static char	*get_next_line_without_breakline(int fd)
{
	char	*line;
	size_t	len;
	char	*cpy;

	line = ft_get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len == 1)
		return (line);
	if (line[len - 1] != '\n')
		return (line);
	cpy = ft_substr(line, 0, len - 1);
	free(line);
	return (cpy);
}
static char	*concat_and_next_line(char **s1, char *s2, int fd)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*res;

	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2 + 1;
	res = (char *) ft_calloc(total_len, sizeof(char));
	ft_strlcpy(res, *s1, total_len);
	ft_strlcpy(res + len1, s2, total_len);
	free(*s1);
	free(s2);
	*s1 = res;
	return (get_next_line_without_breakline(fd));
}


void	init_values(t_data *aux, char **map, char *line)
{
	aux->width = ft_strlen(line);
	aux->height = 0;
	*map = 0;
}



t_data	*sl_read_map(int fd)
{
	char	*line;
	char	*map;
	t_data	aux;
	t_data	*res;

	line = get_next_line_without_breakline(fd);
	if (line == 0)
		return (close(fd), (t_data *) sl_error("El mapa está vacío."));
	init_values(&aux, &map, line);
	while (line && ft_strlen(line) > 0)
	{
		if (aux.width != ft_strlen(line))
			return (close(fd), free(line), free(map),
				(t_data *) sl_error("El mapa es inválido."));
		line = concat_and_next_line(&map, line, fd);
		aux.height++;
	}
	if (line != 0 && ft_strlen(line) == 0)
		return (close(fd), free(map), free(line),
			(t_data *) sl_error("El mapa es inválido."));
	res = sl_verify_map(map, aux.width, aux.height);
	return (close(fd), free(map), res);
}
