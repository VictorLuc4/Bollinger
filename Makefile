##
## Created by Victor Lucas
##

##################
## INSTRUCTIONS ##
##################

## PROD PART ##
SRC			=	input.cpp			\
				bollinger.cpp		\
				main.cpp

CC			=	g++ -o
OBJ			=	$(SRC:.cpp=.o)
NAME		=	bollinger

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(NAME) $(OBJ) $(CXXFLAGS)


## TEST PART ##
SRC_TEST 	=	input.cpp			\
				bollinger.cpp		\
				tests/test.cpp

CTEST 		= 	g++ -lcriterion --coverage -o
OBJ_TEST 	= 	$(SRC_TEST:.cpp=.o)
NAME_TEST 	=	test_run
EXT_TEST 	= 	*.gc*


coverage:	test

test:		$(OBJ_TEST)
			$(CTEST) $(NAME_TEST) $(SRC_TEST) $(CXXFLAGS)
			./$(NAME_TEST)

## COMMON PART ##
CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++11
RM			=	rm -f

clean:
			$(RM) $(OBJ) $(OBJ_TEST) $(NAME_TEST) $(EXT_TEST)

fclean:		clean
			$(RM) $(NAME)

re:			clean fclean all

.PHONY:		all clean fclean re test
