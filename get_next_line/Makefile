# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:23:45 by mtemel            #+#    #+#              #
#    Updated: 2022/04/11 13:42:12 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRCS:.c=.o)

BOBJ = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJ)

bonus:
	gcc $(FLAGS) -c $(BSRCS)
	ar rcs $(NAME) $(BOBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f get_next_line.a

re:	fclean all

.PHONY: all bonus clean fclean re
