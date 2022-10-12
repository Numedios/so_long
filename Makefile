NAME = so_long

CC = gcc
CFLAGS = 

LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		backtracking.c \
		parsing.c \
		read_map.c \
		split_long.c \
		utils.c \
		utils_parsing.c  \
		utils_backtracking.c \
		window.c
		

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) --no-print-directory -C mlx_linux
	$(CC) $(OBJ) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g


%.o : $(SRCPATH)%.c
	@$(CC) $(CFLAGS) -c $^

clean :
	$(MAKE) --no-print-directory clean -C mlx_linux
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re