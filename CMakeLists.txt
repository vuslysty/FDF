cmake_minimum_required(VERSION 3.13)
project(FDF C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)

add_executable(FDF srcs/main.c includes/fdf.h srcs/drawLine.c srcs/map_validator/validation.c srcs/map_validator/is_delimiter.c includes/validator.h srcs/map_validator/read_fdf_map.c)
target_include_directories(FDF PRIVATE ./includes ./libft/includes /usr/local/include)

target_compile_options(FDF PRIVATE -Wall -Wextra -Werror)

SET(LINK_FLAGS    "-lmlx -framework OpenGL -framework AppKit")
#add linker flags
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")
target_link_libraries(FDF LIBFT)