name = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -ggdb3 

SRCS =	so_long.c get_next_line.c get_next_line_utils.c game_utils.c\
	game_utils2.c game_utils3.c game_utils4.c game_utils5.c\
	game_utils6.c game_utils7.c game_utils8.c game_utils9.c\
	game_utils10.c game_utils11.c

obj = $(SRCS:.c=.o)

all: $(name)

$(name): $(obj)
	$(CC) $(obj) -L./minilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(name)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(name)

re: fclean all
