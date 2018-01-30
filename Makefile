#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbrucker <nbrucker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 10:24:37 by nbrucker          #+#    #+#              #
#    Updated: 2017/12/03 10:24:37 by nbrucker         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = name

NAME1 = push_swap

NAME2 = checker

LIBFTDIR = libft/

INCSDIR = includes/

SRCSDIR = srcs/

OBJSDIR = objs/

DIR1 = ps/

DIR2 = ch/

SRCS1 = main.c \
		action.c \
		sort.c \
		make.c \
		tools.c \
		print.c \
		bubble.c \
		quick.c \
		select.c \
		mix.c \
		mid.c \
		reverse.c \
		packet.c \
		len.c \
		look.c \
		help.c \
		reverse_sort.c \
		opti.c

SRCS2 = main.c \
		exe.c \
		action.c \
		make.c

OBJS1 = $(addprefix $(DIR1)$(OBJSDIR),$(SRCS1:.c=.o))

OBJS2 = $(addprefix $(DIR2)$(OBJSDIR),$(SRCS2:.c=.o))

$(DIR1)$(OBJSDIR)%.o: $(DIR1)$(SRCSDIR)%.c
	@mkdir -p $(DIR1)$(OBJSDIR)
	$(CC) $(CFLAGS) -I $(DIR1)$(INCSDIR) -I $(LIBFTDIR)$(INCSDIR) -o $@ -c $<

$(DIR2)$(OBJSDIR)%.o: $(DIR2)$(SRCSDIR)%.c
	@mkdir -p $(DIR2)$(OBJSDIR)
	$(CC) $(CFLAGS) -I $(DIR2)$(INCSDIR) -I $(LIBFTDIR)$(INCSDIR) -o $@ -c $<

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1) -L./$(LIBFTDIR) -lft

$(NAME2): $(OBJS2)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) -L./$(LIBFTDIR) -lft

clean:
	rm -rf $(DIR1)$(OBJSDIR)
	rm -rf $(DIR2)$(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
