cmake_minimum_required(VERSION 3.13)
project(FDF C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)

add_executable(FDF srcs/main.c includes/fdf.h srcs/drawLine.c srcs/map_validator/validation.c srcs/map_validator/is_delimiter.c includes/validator.h srcs/get_color.c srcs/get_copy_map.c srcs/mult_matrix4x4.c "srcs/first_init_transform_matrices.c" srcs/init_matrixes.c srcs/init_matrixes/init_m0.c srcs/init_matrixes/init_m1.c srcs/put_pixel_to_image.c includes/graphic.h srcs/graphic_functions/matrix_operations.c srcs/graphic_functions/tr_rotate.c srcs/graphic_functions/other_tr_matrixes.c srcs/map_validator/validation_new.c srcs/new/init_mas_local.c srcs/graphic_functions/polygon_draw.c srcs/graphic_functions/main.c srcs/new/intersection.c srcs/new/line_clip_and_draw.c srcs/new/dpoint_list_operations.c)
target_include_directories(FDF PRIVATE ./includes ./libft/includes /usr/local/include)

target_compile_options(FDF PRIVATE -Wall -Wextra )

SET(LINK_FLAGS    "-lmlx -framework OpenGL -framework AppKit")
#add linker flags
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")
target_link_libraries(FDF LIBFT)