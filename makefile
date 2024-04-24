# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 02:24:53 by kamsingh          #+#    #+#              #
#    Updated: 2024/04/24 02:26:03 by kamsingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_YELLOW = \033[0;33m
COLOUR_MAGENTA = \033[0;35m
RESET_COLOR = \033[0m

NAME := philo
CFLAGS := -Wall -Wextra -Werror #-g -f

SRCS := main.c  utils.c ruotine.c ini.c dying.c
OBJS := $(SRCS:.c=.o)

CC := cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_YELLOW)PHILOSOPHERS DONE COMPLETELY!$(COLOUR_YELLOW)"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOUR_MAGENTA)PHILOSOPHERS WIPED OUT COMPLETELY!$(COLOUR_MAGENTA)"

re: fclean all

.PHONY: all clean fclean re
