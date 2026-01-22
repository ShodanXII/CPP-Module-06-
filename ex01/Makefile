NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) serializer.hpp Data.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re