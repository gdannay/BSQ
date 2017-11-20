# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 22:08:37 by gdannay           #+#    #+#              #
#    Updated: 2017/07/26 23:36:01 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	bsq

CFILES	=	./srcs/main.c						\
			./srcs/lib.c						\
			./srcs/affichage.c					\
			./srcs/algo.c						\
			./srcs/read_map.c					\
			./srcs/split_and_int.c

FLAGS	=	-Wall	\
			-Wextra	\
			-Werror

HFILES	=	./includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(CFILES) -I $(HFILES) -o $(NAME)

clean:
	rm -f $(NAME)

re : clean all
