NAME = Bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
INC_DIR = includes

SRCS = main.cpp $(wildcard srcs/*.cpp)
INCS = $(wildcard includes/*.hpp)
OBJS = $(SRCS:%.cpp=build/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

build/%.o: %.cpp $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME) *_shrubbery

re: fclean all

.PHONY: all clean fclean re
