/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:55:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/18 14:05:26 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft/ft.h"

# define TILE_SIZE 32

typedef struct s_images
{
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collection;
}				t_images;

typedef	struct s_position
{
	int	x;
	int	y;
}		t_position;

typedef enum e_value
{
	FLOOR = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIONABLE = 'C'
}	t_value;

typedef struct s_data
{
	t_value		*map;
	size_t		width;
	size_t		height;
	int			num_col;
	t_position	*player;
	t_position	*exit;
}				t_data;

/* textures.c */
mlx_image_t	*sl_load_texture(mlx_t *mlx, char *path);
void		sl_print_texture(mlx_t *mlx, mlx_image_t *texture, int x, int y);
mlx_image_t	*sl_translate_texture(t_images *images, char type);

/* load_map_textures.c */
/* void	sl_read_map(mlx_t *mlx, t_images *images); */

/****************  verifications.c: Functions to verify a map *****************/

/**
 * Verifies that the map meets the requirements. If it doesn't meets, return null.
 * @param data the map structure to verify.
 * @returns the map with usefull data if meets the requirements. Else returns null.
 */
t_data  *sl_verify_map(char *map, size_t width, size_t height);


/*******************  parse_file.c: Functions to read a map *******************/

/** 
 * Reads and parses a .ber file in a char array. 
 * It also verifies the input is correct. If something is wrong, returns null.
 * @param filename the name of the file
 * @returns a verified structure with the info of the map or null if any problem.
 */
t_data  *sl_read_map(char *filename);

/**
 * Prints an string error on the standard error output.
 * @param error_str the string to print.
 * @returns NULL.
 */
void    *sl_print_error(char *error_str);


/*******************  data_utils.c: Functions to read a map *******************/

/**
 * Releases a t_data structure
 * @param data the variable to free.
 */
void	sl_free_map(t_data **data);

/**
 * Given a map data, get the value of the position (x,y) in the map.
 * @param data The map data
 * @param x position x in the map
 * @param y position y in the map
 * @returns the 
 */
t_value	sl_get_position(t_data *data, size_t x, size_t y);

#endif
