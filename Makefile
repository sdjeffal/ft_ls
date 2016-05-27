# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdjeffal <sdjeffal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 12:17:01 by sdjeffal          #+#    #+#              #
#*   Updated: 2015/12/12 06:14:33 by sdjeffal         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

CPATH = src/
CFILES =       \
	main.c     \
	parse.c    \
	t_error.c  \
	msgerror.c \
	file.c     \
	core.c     \
	check.c    \
	insert.c   \
	utils.c    \
	print.c    \
	stat.c     \
	chmod.c    \
	print_l.c  \
	display.c  \
	padding.c  \
	stat2.c    \
	free.c     \

IPATH = inc/
IFILES = ft_ls.h
INC = $(addprefix $(IPATH), $(IFILES))

OPATH = obj/
OFILES = $(CFILES:.c=.o)
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling \"$(NAME)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "Successful compilation!---"

$(OPATH)%.o: $(CPATH)%.c $(INC)
	@mkdir -p $(OPATH)
	$(CC) $(CFLAGS) -I inc -c -o $@ $<

clean:
	@echo "Deleting the directory /obj..."
	make -C libft clean
	@rm -rf $(OPATH)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAME)"..."
	make -C libft fclean
	@rm -f $(NAME)
	@echo "Deletion complete !"/

re: fclean all
