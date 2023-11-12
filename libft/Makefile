# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 07:08:03 by acaceres          #+#    #+#              #
#    Updated: 2023/11/08 11:07:19 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAIN FILES ###
SRCS =	srcs/chars/ft_isalnum.c \
	srcs/chars/ft_isalpha.c \
	srcs/chars/ft_isascii.c \
	srcs/chars/ft_isdigit.c \
	srcs/chars/ft_isprint.c \
	srcs/chars/ft_tolower.c \
	srcs/chars/ft_toupper.c \
	srcs/malloc/ft_bzero.c \
	srcs/malloc/ft_calloc.c \
	srcs/malloc/ft_free_2d_arr.c \
	srcs/malloc/ft_free_args.c \
	srcs/malloc/ft_free.c \
	srcs/memory/ft_memchr.c \
	srcs/memory/ft_memcmp.c \
	srcs/memory/ft_memcpy.c \
	srcs/memory/ft_memmove.c \
	srcs/memory/ft_memset.c \
	srcs/prints/ft_putchar_fd.c \
	srcs/prints/ft_putendl_fd.c \
	srcs/prints/ft_putnbr_fd.c \
	srcs/prints/ft_putstr_fd.c \
	srcs/std/ft_atoi.c \
	srcs/std/ft_atol.c \
	srcs/std/ft_itoa.c \
	srcs/strings/ft_split.c \
	srcs/strings/ft_strchr.c \
	srcs/strings/ft_strdup.c \
	srcs/strings/ft_striteri.c \
	srcs/strings/ft_strjoin.c \
	srcs/strings/ft_strlcat.c \
	srcs/strings/ft_strlcpy.c \
	srcs/strings/ft_strlen.c \
	srcs/strings/ft_strmapi.c \
	srcs/strings/ft_strncmp.c \
	srcs/strings/ft_strnstr.c \
	srcs/strings/ft_strrchr.c \
	srcs/strings/ft_strtrim.c \
	srcs/strings/ft_substr.c \
	srcs/get_next_line/get_next_line.c \
	srcs/ft_printf/ft_printf_utils.c \
	srcs/ft_printf/ft_printf.c \

### BONUS FILES ###
SRCSB =	srcs/linked_list/ft_lstnew_bonus.c \
	srcs/linked_list/ft_lstadd_front_bonus.c \
	srcs/linked_list/ft_lstnew_bonus.c \
	srcs/linked_list/ft_lstsize_bonus.c \
	srcs/linked_list/ft_lstlast_bonus.c \
	srcs/linked_list/ft_lstadd_back_bonus.c \
	srcs/linked_list/ft_lstdelone_bonus.c \
	srcs/linked_list/ft_lstclear_bonus.c \
	srcs/linked_list/ft_lstiter_bonus.c \
	srcs/linked_list/ft_lstmap_bonus.c \

#####################################################################################

NAME = libft.a

TARGET = all

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = gcc
C_FLAGS = -Wall -Wextra -Werror
INC = -I includes
AR = ar
AR_FLAGS = -rcs
RM = rm -rf

%.o: %.c
	$(CC) $(INC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSB)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS) $(OBJSB)

all: $(OBJS) $(NAME)

re: fclean
	$(MAKE) $(TARGET)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSB)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re bonus
