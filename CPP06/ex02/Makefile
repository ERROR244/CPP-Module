NAME =  Identify

SRCS = src/main.cpp src/Base.cpp src/A.cpp src/B.cpp src/C.cpp src/func.cpp

CC = c++

CFLAGS = -Wall -Wextra -g3  -I./include -std=c++98

RM = rm -rf

all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
		@$(RM) $(NAME)

re : clean all
