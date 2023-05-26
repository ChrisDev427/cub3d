# Makefile


NAME = cub3d

LIBFT = libft/
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
MLX_PATH =   
OPENGL = -framework OpenGL
APPKIT = -framework AppKit
SRCS =  srcs/cub3d.c \
		srcs/ft_quit.c \
		srcs/parsing/ft_get_map.c \
		srcs/parsing/ft_get_elements.c \
		srcs/parsing/ft_check_map_basics.c \
		srcs/parsing/ft_open.c \
		srcs/ft_error.c \
		srcs/ft_window.c \
		srcs/ft_print_map.c \
		srcs/ft_keymap.c


OBJECT_FILES = $(SRCS:.c=.o)


HEADER = -I./includes

all: $(NAME) 
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILES)
	@echo "$(YELLOW)\n<<<<< libft compiling ... >>>>>\n$(DEFAULT)"
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	@echo "$(YELLOW)\n<<<<< Creating $(NAME) exec file ! ... >>>>>$(DEFAULT)"
	$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) $(MLX_PATH) $(OPENGL) $(APPKIT) libft/libft.a 
	@echo "$(GREEN)\n<<<<< $(NAME) created ! ... >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
clean: 
	@echo "$(RED)\n<<<<< deleting $(NAME) obj. files ! ... >>>>>$(DEFAULT)"
	rm -rf $(OBJECT_FILES) $(OBJECT_BONUS)
	@echo "$(GREEN)<<<<< clean from $(NAME) done ! >>>>>\n$(DEFAULT)"
	$(MAKE) clean -C $(LIBFT)
#------------------------------------------------------------------------------
fclean: clean
	@echo "$(RED)<<<<< deleting $(NAME) exec ! >>>>>\n$(DEFAULT)"
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT)
	@echo "$(GREEN)<<<<< fclean from $(NAME) done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)\n<<<<< $(NAME) make re done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
#------------------------------------------------------------------------------
#DEBUG
# -fsanitize=address
# valgrind --leak-check=full
