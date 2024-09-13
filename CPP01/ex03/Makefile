NAME = violence

SRCS = src/main.cpp src/Weapon.cpp src/HumanA.cpp src/HumanB.cpp

OBJ = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include

AR  = ar rcs
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