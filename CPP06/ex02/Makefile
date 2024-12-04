NAME =  Identify

SRCS = src/main.cpp src/Base.cpp src/A.cpp src/B.cpp src/C.cpp src/func.cpp

OBJ = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror  -I./include -std=c++98

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
