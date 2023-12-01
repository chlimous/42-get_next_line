# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 05:11:53 by chlimous          #+#    #+#              #
#    Updated: 2023/12/01 19:04:34 by chlimous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = reader
NAME2 = wrongfd
NAME3 = stdin
NAME_BONUS1 = reader_bonus
NAME_BONUS2 = wrongfd_bonus
NAME_BONUS3 = stdin_bonus

SRCS = $(addprefix ../, get_next_line.c get_next_line_utils.c)
SRCS_BONUS = $(addprefix ../, get_next_line_bonus.c get_next_line_utils_bonus.c)

SRCS1 = $(SRCS) main_reader.c
SRCS2 = $(SRCS) main_wrongfd.c
SRCS3 = $(SRCS) main_stdin.c
SRCS_BONUS1 = $(SRCS_BONUS) main_reader.c
SRCS_BONUS2 = $(SRCS_BONUS) main_wrongfd.c
SRCS_BONUS3 = $(SRCS_BONUS) main_stdin.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS3 = $(SRCS3:.c=.o)
OBJS_BONUS1 = $(SRCS_BONUS1:.c=.o)
OBJS_BONUS2 = $(SRCS_BONUS2:.c=.o)
OBJS_BONUS3 = $(SRCS_BONUS3:.c=.o)

INCLUDE = ..

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

mandatory: $(NAME1) $(NAME2) $(NAME3) 

bonus: $(NAME_BONUS1) $(NAME_BONUS2) $(NAME_BONUS3)

all: mandatory bonus

$(NAME1): $(OBJS1)
ifeq ($(BUFFER_SIZE),)
	@echo "Compiling using default BUFFER_SIZE"
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)
else
	@echo "Compiling using BUFFER_SIZE=$(BUFFER_SIZE)"
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1) -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

$(NAME3): $(OBJS3)
	$(CC) $(CFLAGS) $(OBJS3) -o $(NAME3)

$(NAME_BONUS1): $(OBJS_BONUS1)
ifeq ($(BUFFER_SIZE),)
	@echo "Compiling using default BUFFER_SIZE"
	$(CC) $(CFLAGS) $(OBJS_BONUS1) -o $(NAME_BONUS1)
else
	@echo "Compiling using BUFFER_SIZE=$(BUFFER_SIZE)"
	$(CC) $(CFLAGS) $(OBJS_BONUS1) -o $(NAME_BONUS1) -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

$(NAME_BONUS2): $(OBJS_BONUS2)
	$(CC) $(CFLAGS) $(OBJS_BONUS2) -o $(NAME_BONUS2)

$(NAME_BONUS3): $(OBJS_BONUS3)
	$(CC) $(CFLAGS) $(OBJS_BONUS3) -o $(NAME_BONUS3)

clean:
	rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS_BONUS1) $(OBJS_BONUS2) $(OBJS_BONUS3)

clean_m:
	rm -f $(OBJS1) $(OBJS2) $(OBJS3)

clean_bonus:
	rm -f $(OBJS_BONUS1) $(OBJS_BONUS2) $(OBJS_BONUS3)

fclean: clean
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME_BONUS1) $(NAME_BONUS2) $(NAME_BONUS3)

fclean_m: clean_m
	rm -f $(NAME1) $(NAME2) $(NAME3)

fclean_bonus: clean_bonus
	rm -f $(NAME_BONUS1) $(NAME_BONUS2) $(NAME_BONUS3)

re: fclean all

re_bonus: fclean_bonus bonus

re_m: fclean_m mandatory

.PHONY: all clean clean_m clean_bonus fclean fclean_m fclean_bonus re re_bonus re_m mandatory bonus
