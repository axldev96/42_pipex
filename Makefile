# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 09:31:44 by acaceres          #+#    #+#              #
#    Updated: 2023/11/15 04:04:00 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

MAIN_TARGET = all

CC = gcc

C_FLAGS =  -Wall -Wextra -Werror -std=c99 -fsanitize=address -g3

$(RM) = rm -rf

SRCS_FILES = procss/parent.c \
			 procss/first_child.c \
			 procss/middle_child.c \
			 procss/last_child.c \
			 utils/set_pipx.c \
			 utils/get_path.c \
			 utils/get_execve_av.c \
			 utils/heredoc.c \
			 args/args.c \
			 main.c

SRCS_DIR = srcs/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:%.c=%.o)

INC_DIR = includes/

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

INC_FLAGS = -I $(INC_DIR)
INC_FLAGS += -I $(LIBFT_DIR)/$(INC_DIR)

LD_FLAGS = 

%.o: %.c
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

re: fclean
	$(MAKE) $(MAIN_TARGET)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

.PHONY: all clean fclean re
