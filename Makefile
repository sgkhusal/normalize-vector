# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:27:02 by sguilher          #+#    #+#              #
#    Updated: 2022/12/08 17:40:32 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			normalize

SRCS =			normalize.c utils1.c utils2.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)
HEADERS	=		normalize.h
VPATH	=		src
INCLUDE	=		-I./

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# colors
YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

# **************************************************************************** #
# rules

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(OBJS_DIR) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "          normalize created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
		$(RM_DIR) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
