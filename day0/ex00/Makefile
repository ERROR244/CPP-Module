NAME = MyAwesome

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3 -g3

SRCS = 	MyAwesome.cpp

OBJ = $(SRCS:.cpp=.o)

AR  = ar rcs

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
		@$(RM) $(OBJ)

fclean :
		@$(RM) $(OBJ) $(NAME)

re : fclean all