# Makefile


NAME = cub3D

LIBFT = libft/
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
MLX_PATH =  -L /usr/local/lib/
OPENGL = -framework OpenGL
APPKIT = -framework AppKit
SRCS =  srcs/cub3d.c \
		srcs/ft_quit.c \
		srcs/parsing/ft_init.c \
		srcs/parsing/ft_init_minimap.c \
		srcs/parsing/ft_get_colors.c \
		srcs/parsing/ft_get_map.c \
		srcs/parsing/ft_split_map_elem.c \
		srcs/parsing/ft_check_map.c \
		srcs/parsing/ft_open.c \
		srcs/ft_error.c \
		srcs/ft_key.c \
		srcs/ft_window.c \
		srcs/ft_player_position.c \
		srcs/ft_run.c \
		srcs/ft_camera.c \
		srcs/ft_mini_map.c \
		srcs/ft_mini_map_utils.c 


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
	@rm -rf $(OBJECT_FILES) $(OBJECT_BONUS)
	@echo "$(GREEN)<<<<< clean from $(NAME) done ! >>>>>\n$(DEFAULT)"
#	@$(MAKE) clean -C $(LIBFT)
#------------------------------------------------------------------------------
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
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
