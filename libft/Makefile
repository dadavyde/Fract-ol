# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:59:43 by dadavyde          #+#    #+#              #
#    Updated: 2017/11/09 18:59:44 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS = -c -Wall -Wextra -Werror

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"

SOURCES = memory/ft_memset.c memory/ft_memcpy.c memory/ft_memccpy.c memory/ft_memmove.c \
		memory/ft_memdel.c memory/ft_memalloc.c memory/ft_memchr.c memory/ft_memcmp.c \
		str/ft_strlen.c str/ft_strdup.c str/ft_strcpy.c str/ft_strncpy.c \
		str/ft_strcat.c str/ft_strncat.c str/ft_strlcat.c str/ft_strchr.c \
		str/ft_strrchr.c str/ft_strstr.c str/ft_strnstr.c str/ft_strcmp.c \
		str/ft_strncmp.c str/ft_strnew.c str/ft_strdel.c str/ft_strclr.c \
		str/ft_striter.c str/ft_striteri.c str/ft_strmap.c str/ft_strmapi.c \
		str/ft_strequ.c str/ft_strnequ.c str/ft_strsub.c str/ft_strjoin.c \
		str/ft_strtrim.c str/ft_strsplit.c \
		is/ft_isalpha.c is/ft_isdigit.c is/ft_isalnum.c is/ft_isascii.c is/ft_isprint.c \
		put/ft_putchar.c put/ft_putstr.c put/ft_putendl.c put/ft_putnbr.c \
		put/ft_put_carray.c put/ft_put_iarray.c put/ft_putnbr_fd.c \
		put/ft_putchar_fd.c put/ft_putstr_fd.c put/ft_putendl_fd.c \
		lists/ft_lstnew.c lists/ft_lstdelone.c lists/ft_lstdel.c lists/ft_lstadd.c \
		lists/ft_lstiter.c lists/ft_lstmap.c \
		find/ft_find_all_c.c find/ft_find_after_c.c find/ft_find_c.c \
		ft_del_all_c.c ft_arraycpy.c get_next_line.c ft_bzero.c ft_atoi.c \
		ft_toupper.c ft_tolower.c ft_itoa.c

HEADERS = include/libft.h include/get_next_line.h 
INCLUDES = -I include/

OBJ = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
OBJDIR = obj/

NAME = libft.a

all: $(NAME)

$(NAME):  $(OBJ) $(HEADERS) $(OBJDIR)
	@ar rc $(NAME) $(OBJ)
	@echo ${BG}"[ ✓ ] $@"

$(OBJDIR)%.o: source/memory/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)
	@echo ${BG}"[ ✓ ] $@"

$(OBJDIR)%.o: source/str/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)


$(OBJDIR)%.o: source/is/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)


$(OBJDIR)%.o: source/put/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)


$(OBJDIR)%.o: source/lists/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)


$(OBJDIR)%.o: source/find/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJDIR)%.o: source/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $< -o $@ $(INCLUDES)

clean: 
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@echo ${BR}"[ ✗ ] $(OBJDIR)"

fclean: clean
	@rm -f $(NAME)
	@echo ${BR}"[ ✗ ] $(NAME)"

real: fclean all
