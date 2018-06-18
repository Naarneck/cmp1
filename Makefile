# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izelensk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:17:24 by izelensk          #+#    #+#              #
#    Updated: 2017/08/07 16:21:45 by izelensk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

SRCS = main.cpp

OBJS = main.o

JUNK = $(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch)

all:$(NAME)

$(NAME): $(OBJS)
	clang++ -o $(NAME) -Wall -Wextra -Werror  $(SRCS)
	@rm -rf $(JUNK)
	@echo "compiled"

clean:
	@rm -rf $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned"

re: fclean all
