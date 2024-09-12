NAME =  Abstract

SRCS = src/main.cpp src/AMateria.cpp src/Character.cpp src/Cure.cpp src/Ice.cpp src/ICharacter.cpp src/IMateriaSource.cpp src/MateriaSource.cpp

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
