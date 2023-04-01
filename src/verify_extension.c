/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_extension.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:41:09 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/04/01 18:41:40 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_open_ber_extension(char	*filename)
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
