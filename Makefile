# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:08:51 by tokazaki          #+#    #+#              #
#    Updated: 2023/07/18 11:47:57 by tokazaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Files & Command +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
SRCS_DIR = srcs
OBJS_DIR = objs
#OBJS_DIR = ./objs

SRCS = $(addprefix $(SRCS_DIR)/, \
		util_swap.c \
		util_push.c \
		util_rotate.c \
		util_reverse_rotate.c \
		push_swap.c \
		make_node.c \
		process_args.c \
		debug.c \
		check_sort.c \
		)
OBJS = $(SRCS:.c=.o)
#OBJS	= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I./libft
RM		= rm -f

# Libft & Debug +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

DEBUG			= debug
CFLAGS_DEBUG	= $(CFLAGS) -g -fsanitize=address
#CFLAGS_DEBUG	= $(CFLAGS) -g srcs/debug.c

# Mandatory target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $@
	@make clean

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM)r $(NAME).dSYM

re: fclean all

# Other target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
