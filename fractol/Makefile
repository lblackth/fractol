FRAMEWORKS=-I MLX/ -L MLX/ -lmlx -framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fractol
SRCS=*.c
OBJS=${SRCS:.c=.o}
CC=gcc
REMOVE=rm -f
HEADER=fractol.h

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(HEADER)
	make -C MLX/
	$(CC) $(SRCS) -o $(NAME) $(FLAGS) $(FRAMEWORKS)
clean:
	@make -C MLX/ clean
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re