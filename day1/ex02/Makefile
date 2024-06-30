NAME = out

SRCS = main.cpp

OBJ = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3 -g3 #-fsanitize=address #-w #-v

AR  = ar rcs
RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all