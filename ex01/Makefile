NAME = Bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
INC_DIR = includes

SRCS = main.cpp $(wildcard srcs/*.cpp)
INCS = $(wildcard includes/*.hpp)
OBJS = $(SRCS:%.cpp=build/%.o)

RED	 = \e[31m
GREEN   = \e[32m
YELLOW  = \e[33m
RESET   = \e[m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREEN)Linking $@$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^
	@printf "$(GREEN)Build complete$(RESET)\n"

build/%.o: %.cpp $(INCS)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $<$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@printf "$(RED)Cleaning object files$(RESET)\n"
	@rm -rf build

fclean: clean
	@printf "$(RED)Cleaning executable$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re