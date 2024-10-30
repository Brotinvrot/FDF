NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -g

LDFLAGS = ./minilibx-linux/libmlx.a -lXext -lX11 -lm

# если ты пишешь полностью " libmlx.a " название файла
# то флаг -lmlx уже не требуется, а если нет явного
# указания на файл библиотеки то пиши вот так
# CFLAGS = -L (путь от места расположения мейк файла)
# ./minilibx-linux/ и флаг для поиска файла библиотеки -lmlx

SRC = main.c draw.c read_line.c gnl.c liba.c rotate.c color.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean  all

.PHONY: all clean fclean re
