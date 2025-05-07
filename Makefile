NAME := cub3D
CC := cc

SRCS_DIR := srcs
LIBFT_DIR := libft
MLX_DIR := minilibx-linux/

LIBFT_LIB := -L$(LIBFT_DIR) -lft
LIBFT_INC := -I./libft/includes

MLX_LIB := -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_INC := -I$(MLX_DIR)

INC_FLAGS := -Iincludes $(MLX_INC) $(LIBFT_INC)
CFLAGS := -Wall -Wextra -Werror -g $(INC_FLAGS)
LD_FLAGS := $(MLX_LIB) $(LIBFT_LIB)
MAKEFLAGS += --no-print-directory

SRCS := $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/parse_colors.c \
		$(SRCS_DIR)/parse_textures.c \
		$(SRCS_DIR)/parse_map.c \
		$(SRCS_DIR)/parsing_utils.c \
		$(SRCS_DIR)/print.c \
		$(SRCS_DIR)/parsing.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling libraries..."
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@echo "Compiling cub3D..."
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LD_FLAGS)
	@echo "cub3D compiled."

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS)
	@echo "clean done."

fclean: clean
	@make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "fclean done."

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJS)
