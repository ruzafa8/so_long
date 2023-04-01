/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:50:21 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/04/01 18:08:20 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/**
 * validate the extension is correct. (it should finish in .ber)
 * @param filename The name of the file to validate.
 * @return a positive number if the filename has got the correct extension
 * 	or 0 if it is incorrect.
 */
static int	valid_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len > 4
		&& filename[len - 4] == '.'
		&& filename[len - 3] == 'b'
		&& filename[len - 2] == 'e'
		&& filename[len - 1] == 'r');
}

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

int	open_ber_extension(char	*filename)
{
	int	fd;

	if (!valid_extension(filename))
	{
		sl_error("La extensión no es .ber.");
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		sl_error("Hubo un problema con la lectura del fichero.");
	return (fd);
}

t_data	*sl_read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*map;
	t_data	aux;
	t_data	*res;

	fd = open_ber_extension(filename);
	if (fd < 0)
		return (0);
	line = get_next_line_without_breakline(fd);
	if (line == 0)
		return (close(fd), (t_data *) sl_error("El mapa está vacío."));
	aux.width = ft_strlen(line);
	aux.height = 0;
	map = 0;
	while (line && ft_strlen(line) > 0)
	{
		if (aux.width != ft_strlen(line))
			return (close(fd), free(line), free(map),
				(t_data *) sl_error("El mapa no es rectangular."));
		line = concat_and_next_line(&map, line, fd);
		aux.height++;
	}
	res = sl_verify_map(map, aux.width, aux.height);
	return (close(fd), free(map), res);
}
