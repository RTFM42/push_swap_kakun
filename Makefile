# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:08:51 by tokazaki          #+#    #+#              #
#    Updated: 2023/07/12 14:40:11 by tokazaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Files & Command +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, \
	push_swap.c)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./libft
RM = rm -f

# Libft & Debug +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

DEBUG			= debug
CFLAGS_DEBUG	= $(CFLAGS) -g -fsanitize=address

# Mandatory target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

# Other target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
