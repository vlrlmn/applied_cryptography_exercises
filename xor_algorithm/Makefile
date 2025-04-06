NAME = xor_encryption

SRC = main.c \

CC = cc 

CCFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		@$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
		@rm -f $(OBJ)

all: $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re