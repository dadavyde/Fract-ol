# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 12:09:18 by dadavyde          #+#    #+#              #
#    Updated: 2018/02/17 12:09:21 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -c -Wall -Wextra -Werror
FDF_FLAGS = -lm -lmlx -framework OpenGL -framework AppKit

SOURCES = source/main.c source/make_fractal.c source/error_file.c\
		source/find_iter_main_fractal.c source/parse_fractal.c\
        source/find_color.c source/tree_fractals.c source/key_events.c\
        source/mouse_events.c source/which_fractal.c source/draw_lines.c\
        source/find_iter_bonus_fractal.c

HEADERS = include/structs.h include/fractol.h 
INCLUDES = -I libft/ -I include/

OBJ = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
OBJDIR = obj/

LIBFT = libft/libft.a
NAME = fractol

all: $(NAME)

$(NAME): $(HEADERS) $(OBJDIR) $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(FDF_FLAGS) -o $@ $(LIBFT)

$(OBJDIR)%.o: source/%.c
	$(CC)  $(C_FLAGS) $< -o $@ $(INCLUDES)

$(LIBFT):
	make -C libft

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	echo $(OBJ)
	rm -f $(NAME)

re: fclean all
