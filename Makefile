# Makefile


NAME = cub3D

LIBFT = libft/
CC = gcc -ffast-math
CFLAGS = -Wall -Wextra -Werror -g -O3 #-fsanitize=address
MLX_PATH =  -L /usr/local/lib/
OPENGL = -framework OpenGL
APPKIT = -framework AppKit
SRCS =  srcs/cub3d.c \
		srcs/ft_quit.c \
		srcs/ft_title.c \
		srcs/ft_error.c \
		srcs/ft_print_specs.c \
		srcs/ft_key.c \
		srcs/ft_player_moves.c \
		srcs/ft_position_direction.c \
		srcs/ft_run.c \
		srcs/ft_raycasting.c \
		srcs/ft_camera.c \
		srcs/ft_go_left.c \
		srcs/ft_go_right.c \
		srcs/ft_speed.c \
		srcs/parsing/ft_init.c \
		srcs/parsing/ft_get_colors.c \
		srcs/parsing/ft_get_map.c \
		srcs/parsing/ft_set_map_cpy.c \
		srcs/parsing/ft_split_map_elem.c \
		srcs/parsing/ft_check_map.c \
		srcs/parsing/ft_check_ext.c \
		srcs/parsing/ft_enlarge_map.c \
		srcs/images/ft_init_textures.c \
		srcs/images/ft_vertical_draw.c \
		srcs/images/ft_init_images.c \
		srcs/images/ft_my_pixel_put.c \
		srcs/minimap/ft_minimap.c \
		srcs/minimap/ft_minimap_print_utils.c \
		srcs/minimap/ft_minimap_init.c

OBJECT_FILES = $(SRCS:.c=.o)
HEADER = -I ./includes
all: $(NAME) 
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	@printf "$(YELLOW)Compiling $(NAME): << $< >>\033[K\r$(DEFAULT)"

$(NAME): $(OBJECT_FILES)
	@echo "\n"

#	@echo "$(YELLOW)<<<<< libft compiling ... >>>>>\n$(DEFAULT)"
	@$(MAKE) -C $(LIBFT)
	@cp ./libft/libft.a $(NAME)
	@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) $(MLX_PATH) -lmlx $(OPENGL) $(APPKIT) libft/libft.a 
	@echo "$(GREEN)<<<<< $(NAME) created ! ... >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
clean: 
	@rm -rf $(OBJECT_FILES)
	@$(MAKE) clean -C $(LIBFT)
	@echo "$(GREEN)<<<<< clean from $(NAME) done ! >>>>>\n$(DEFAULT)"
#	@$(MAKE) clean -C $(LIBFT)
#------------------------------------------------------------------------------
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT)
	@echo "$(GREEN)<<<<< fclean from $(NAME) done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)<<<<< $(NAME) make re done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------

#COLORS
RED = \033[3;31m
GREEN = \033[3;32m
YELLOW = \033[3;33m
DEFAULT = \033[0m
#------------------------------------------------------------------------------
#DEBUG
# -fsanitize=address
# valgrind --leak-check=full
# find . -type f -name "*.o" -delete