NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRCS =	./srcs/do_operation.c\
		./srcs/draw_line.c\
		./srcs/draw_map.c\
		./srcs/fps.c\
		./srcs/get_color.c\
		./srcs/get_copy_map.c\
		./srcs/help_function.c\
		./srcs/help_instructions.c\
		./srcs/init_functions.c\
		./srcs/init_mas_local.c\
		./srcs/line_clip_and_draw.c\
		./srcs/main.c\
		./srcs/paint_rainbow_image.c\
		./srcs/map_validator/is_delimiter.c\
		./srcs/map_validator/validation.c\
		./srcs/matrix_functions/matrix_operations.c\
		./srcs/matrix_functions/other_tr_matrixes.c\
		./srcs/matrix_functions/projections.c\
		./srcs/matrix_functions/tr_rotate.c\
		./srcs/matrix_functions/tr_rotate2.c

INC =	./includes/fdf.h\
		./includes/graphic.h\
		/usr/local/include

OBJ = $(SRCS:.c=.o)

all: libft $(NAME)

.PHONY : libft
libft:
	@make -C ./libft

$(NAME): $(OBJ) ./libft/libft.a
	@echo "Building of $(NAME)..."
	@gcc -o $(NAME) $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(INC) 
	gcc $(FLAGS) -I./includes -I./libft/includes -o $@ -c $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all