/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:55:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 18:43:10 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft/ft.h"

# define TILE_SIZE 64

typedef struct s_images
{
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	**wall;
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
	COLLECTIONABLE = 'C',
	INVALID = 0
}	t_value;

typedef struct s_data
{
	t_value		*map;
	size_t		width;
	size_t		height;
	int			num_col;
	t_position	*player;
	t_position	*exit;
	t_images	*images;
	mlx_t		*mlx;
}				t_data;

/******************  textures.c: Functions to load textures *******************/

/**
 *  
 */
mlx_image_t	*sl_load_texture(mlx_t *mlx, char *path);

/**
 * Prints a valid texture in a (x, y) position at mlx.
 * @param data
 * @param x
 * @param y
 */
void	sl_print_texture(t_data *data, t_value value, int x, int y);

/**
 * Translates a valid value of a map to a image texture to be printed.
 * @param data the data game.
 * @param x
 * @param y
 * @returns the image to be printable by mlx lib.
 */
mlx_image_t	*sl_translate_position(t_data *data, int x, int y);
mlx_image_t	*sl_translate_texture(t_data *data, t_value type);
void	sl_print_position(t_data *data, int x, int y);

/**
 * Prints a map given a image map.
 * @param data map information structure.
 */
void	sl_print_map(t_data *data);


/* load_map_textures.c */
void	sl_load_images(t_data *game);

/****************  verifications.c: Functions to verify a map *****************/

/**
 * Verifies that the map meets the requirements. If it doesn't meets, return null.
 * @param data the map structure to verify.
 * @returns the map with usefull data if meets the requirements. Else returns null.
 */
t_data  *sl_verify_map(char *map, size_t width, size_t height);

/**********  verifications_valid_chars.c: Functions to verify a map ***********/

/**
 * 
 */
t_value		*sl_validate_chars(char *map, size_t width, size_t height);


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
void    *sl_error(char *error_str);


/*******************  data_utils.c: Functions to read a map *******************/

/**
 * Releases a t_data structure
 * @param data the variable to free.
 */
void	sl_free_data(t_data **data);

/**
 * Given a map data, get the value of the position (x,y) in the map.
 * @param data The map data
 * @param x position x in the map
 * @param y position y in the map
 * @returns the value of the position (x, y) in the map.
 */
t_value	sl_get_position(t_data *data, size_t x, size_t y);

#endif
