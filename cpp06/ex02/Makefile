NAME = realType

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -rf

INCS = Base.hpp A.hpp B.hpp C.hpp

SRCS = main.cpp Base.cpp

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR) *.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re