# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 05:11:53 by chlimous          #+#    #+#              #
#    Updated: 2023/12/22 15:34:26 by chlimous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = reader
NAME2 = wrongfd
NAME3 = stdin
NAME4 = chrono
NAME_BONUS1 = reader_bonus
NAME_BONUS2 = wrongfd_bonus
NAME_BONUS3 = stdin_bonus
NAME_BONUS4 = checkfd_bonus
NAME_BONUS5 = chrono_bonus
NAME_BONUS6 = checkfdmax

SRCS_M = $(addprefix ../, get_next_line.c get_next_line_utils.c)
SRCS_BONUS = $(addprefix ../, get_next_line_bonus.c get_next_line_utils_bonus.c)

SRCS1 = $(SRCS_M) main_reader.c
SRCS2 = $(SRCS_M) main_wrongfd.c
SRCS3 = $(SRCS_M) main_stdin.c
SRCS4 = $(SRCS_M) main_chrono.c
SRCS_BONUS1 = $(SRCS_BONUS) main_reader.c
SRCS_BONUS2 = $(SRCS_BONUS) main_wrongfd.c
SRCS_BONUS3 = $(SRCS_BONUS) main_stdin.c
SRCS_BONUS4 = $(SRCS_BONUS) main_checkfd_bonus.c
SRCS_BONUS5 = $(SRCS_BONUS) main_chrono.c
SRCS_BONUS6 = main_checkfdmax.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS3 = $(SRCS3:.c=.o)
OBJS4 = $(SRCS4:.c=.o)
OBJS_BONUS1 = $(SRCS_BONUS1:.c=.o)
OBJS_BONUS2 = $(SRCS_BONUS2:.c=.o)
OBJS_BONUS3 = $(SRCS_BONUS3:.c=.o)
OBJS_BONUS4 = $(SRCS_BONUS4:.c=.o)
OBJS_BONUS5 = $(SRCS_BONUS5:.c=.o)
OBJS_BONUS6 = $(SRCS_BONUS6:.c=.o)

INCLUDE = ..

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
ifeq ($(BUFFER_SIZE),)
	@echo "Compiling using default BUFFER_SIZE"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
else
	@echo "Compiling using BUFFER_SIZE=$(BUFFER_SIZE)"
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_SIZE)
endif

mandatory: $(NAME1) $(NAME2) $(NAME3) $(NAME4)

bonus: $(NAME_BONUS1) $(NAME_BONUS2) $(NAME_BONUS3) $(NAME_BONUS4) $(NAME_BONUS5) $(NAME_BONUS6)

all: mandatory bonus

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

$(NAME3): $(OBJS3)
	$(CC) $(CFLAGS) $(OBJS3) -o $(NAME3)

$(NAME4): $(OBJS4)
	$(CC) $(CFLAGS) $(OBJS4) -o $(NAME4)

$(NAME_BONUS1): $(OBJS_BONUS1)
	$(CC) $(CFLAGS) $(OBJS_BONUS1) -o $(NAME_BONUS1)

$(NAME_BONUS2): $(OBJS_BONUS2)
	$(CC) $(CFLAGS) $(OBJS_BONUS2) -o $(NAME_BONUS2)

$(NAME_BONUS3): $(OBJS_BONUS3)
	$(CC) $(CFLAGS) $(OBJS_BONUS3) -o $(NAME_BONUS3)

$(NAME_BONUS4): $(OBJS_BONUS4)
	$(CC) $(CFLAGS) $(OBJS_BONUS4) -o $(NAME_BONUS4)

$(NAME_BONUS5): $(OBJS_BONUS5)
	$(CC) $(CFLAGS) $(OBJS_BONUS5) -o $(NAME_BONUS5)

$(NAME_BONUS6): $(OBJS_BONUS6)
	$(CC) $(CFLAGS) $(OBJS_BONUS6) -o $(NAME_BONUS6)

clean: clean_m clean_bonus

clean_m:
	rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)

clean_bonus:
	rm -f $(OBJS_BONUS1) $(OBJS_BONUS2) $(OBJS_BONUS3) $(OBJS_BONUS4) $(OBJS_BONUS5) $(OBJS_BONUS6)

fclean: fclean_m fclean_bonus

fclean_m: clean_m
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)

fclean_bonus: clean_bonus
	rm -f $(NAME_BONUS1) $(NAME_BONUS2) $(NAME_BONUS3) $(NAME_BONUS4) $(NAME_BONUS5) $(NAME_BONUS6)

re: fclean all

re_bonus: fclean_bonus bonus

re_m: fclean_m mandatory

.PHONY: all clean clean_m clean_bonus fclean fclean_m fclean_bonus re re_bonus re_m mandatory bonus
