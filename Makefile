##
## Created by Victor Lucas
##

CC	=	g++ -o

RM	=	rm -f

SRC	=	input.cpp		\
		bollinger.cpp		\
		main.cpp

SRC_TEST =	input.cpp		\
		bollinger.cpp		\
		tests/test.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST = 	$(SRC_TEST:.cpp=.o)

NAME	=	bollinger

CXXFLAGS =	-Wall -Wextra -Werror -std=c++11

all:		$(NAME)

coverage:	test

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ) $(CXXFLAGS)

test:		$(OBJ_TEST)
		g++ -lcriterion --coverage -o test_run $(SRC_TEST) $(CXXFLAGS)
		./test_run

clean:
		$(RM) $(OBJ) $(OBJ_TEST) test_run *.gc*

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean re test
