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

SRC =	ft_strcmp.c ft_strlen.c ft_strclen.c ft_strcpy.c ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c ft_strncpy.c ft_strcat.c ft_strdup.c ft_strncat.c\
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strequ.c ft_strnequ.c\
	ft_strjoin.c ft_strnjoin.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_bzero.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_itoa.c ft_atoi.c\
	ft_memcpy.c ft_memset.c ft_memalloc.c ft_memdel.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_memccpy.c ft_putchar_fd.c ft_putendl.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlcat.c ft_strmap.c ft_putstr_fd.c ft_strnstr.c ft_putendl_fd.c\
	ft_toupper.c ft_tolower.c ft_isspace.c ft_strsplit.c ft_putnendl.c\
	ft_putnbr_fd.c ft_strmapi.c ft_striter.c ft_striteri.c ft_lstmap.c\
	ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c\
	ft_puttabstr.c ft_vputnbr.c ft_vputchar.c ft_arraymap.c ft_abs.c\
	ft_strtrimi.c ft_strrev.c ft_strndup.c ft_swap.c

SRCOBJ = $(SRC:.c=.o)

OBJDIR = obj/

CFLAG = -Wall -Werror -Wextra

NAME = libft.a

CC = gcc

all: $(NAME)

$(NAME):
	@echo "Compiling library "$(NAME)"..."
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAG) -c $(SRC)
	@mv $(SRCOBJ) $(OBJDIR)
	ar crs $(NAME) $(addprefix $(OBJDIR), $(SRCOBJ))
	@ranlib $(NAME)
	@echo "Compilation success !"
	@echo "---"

.PHONY: clean fclean re

clean:
	@echo "Deleting the directory /obj..."
	@rm -rf $(OBJDIR)
	@rm -f $(SRCOBJ)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAME)"..."
	@rm -f $(NAME)
	@echo "Deletion complete !"

re: fclean all
