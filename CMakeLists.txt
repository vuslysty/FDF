cmake_minimum_required(VERSION 3.13)
project(FDF C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)

add_executable(FDF srcs/main.c includes/fdf.h srcs/draw_line.c srcs/map_validator/validation.c srcs/map_validator/is_delimiter.c srcs/get_color.c srcs/get_copy_map.c includes/graphic.h srcs/matrix_functions/matrix_operations.c srcs/matrix_functions/tr_rotate.c srcs/matrix_functions/other_tr_matrixes.c srcs/init_mas_local.c srcs/line_clip_and_draw.c srcs/matrix_functions/tr_rotate2.c srcs/matrix_functions/projections.c srcs/draw_map.c srcs/fps.c srcs/paint_rainbow_image.c srcs/do_operation.c srcs/help_function.c srcs/init_functions.c srcs/help_instructions.c)
target_include_directories(FDF PRIVATE ./includes ./libft/includes /usr/local/include)

target_compile_options(FDF PRIVATE -Wall -Wextra -Werror)

SET(LINK_FLAGS    "-lmlx -framework OpenGL -framework AppKit")
#add linker flags
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")
target_link_libraries(FDF LIBFT)