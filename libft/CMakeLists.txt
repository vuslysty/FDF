cmake_minimum_required(VERSION 3.12)
project(LIBFT LANGUAGES C)

# functions find all sourses in path and add their to target
AUX_SOURCE_DIRECTORY(./srcs LIB_SRCS)
AUX_SOURCE_DIRECTORY(./srcs/ft_printf PF_SRCS)

# create library with sourses
add_library(LIBFT STATIC ${LIB_SRCS} ${PF_SRCS} srcs/ft_get_number.c srcs/ft_atoi_base.c srcs/ft_is_whitespace.c srcs/ft_strtolower.c)
# Specify the foulder with headers for library (or executable)
target_include_directories(LIBFT PRIVATE ./includes)
# Specify compile options for library
#SET(COMPILE_FLAGS "-Wall -Wextra -Werror")
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
target_compile_options(LIBFT PRIVATE -Wall -Wextra -Werror)

target_compile_options(LIBFT PRIVATE )
