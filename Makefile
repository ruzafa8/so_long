NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./lib/
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a\
		   -L "/Users/aruzafa-/.brew/opt/glfw/lib/"
SRCS	:= src/main.c src/textures_map.c src/textures_load.c src/textures_utils.c\
			src/verifications.c src/verifications_valid_chars.c\
			src/player_move.c\
			src/parse_file.c src/data_utils.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx
