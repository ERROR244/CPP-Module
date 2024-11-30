NAME =  real

SRCS = src/main.cpp src/real.cpp src/A.cpp src/B.cpp src/C.cpp src/func

OBJ = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -g3  -I./include -std=c++98

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		@$(RM) $(OBJ)

fclean : clean
		@$(RM) $(NAME)

re : fclean all
