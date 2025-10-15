# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamorcil <gamorcil@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 16:34:56 by gamorcil          #+#    #+#              #
#    Updated: 2025/10/13 16:34:57 by gamorcil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

# Archivos fuente
SRCS = main.c \
       errors.c \
	   set_list.c \
	   ft_atol.c \
	   set_stack.c \
	   free_memory.c \
	   sort.c \
	   sort_three.c \
	   movements.c \
	   movements_utils.c \


OBJS = $(SRCS:.c=.o)

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Includes
INCLUDES = -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

# Regla principal
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# Compilar objetos
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilar libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilar ft_printf
$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

# Limpiar objetos
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re
	# Añade esto a tu Makefile

# Regla para debug (sin flags de 42, con -g para gdb)
debug: CFLAGS = -g
debug: fclean $(NAME)
	@echo "Compiled in DEBUG mode (no -Wall -Wextra -Werror, with -g)"

# O si quieres una regla "force" que compile directamente sin limpiar
force:
	$(CC) -g $(INCLUDES) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "Force compiled in DEBUG mode"
