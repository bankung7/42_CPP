NAME = interface

CC = c++

CFLAGS = -Wall -Wextra -std=c++98 -g

RM = rm -rf

INCS = AMateria.hpp MateriaSource.hpp IMateriaSource.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp

SRCS = main.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp

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