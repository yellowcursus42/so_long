NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

DIR_LIBFT 		= ./lib/libft/
LIB_LIBFT 		= ./lib/libft/libft.a
DIR_PRINTF 		= ./lib/ft_printf/
LIB_PRINTF 		= ./lib/ft_printf/libftprintf.a
DIR_GNL 		= ./lib/get_next_line
LIB_GNL 		= ./lib/get_next_line/libgnl.a

CC 				= clang

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				so_long.c			\
				ft_check_map.c		\
				ft_close_game.c		\
				ft_free_memory.c	\
				ft_handle_input.c	\
				ft_init_game.c		\
				ft_init_map.c		\
				ft_render_map.c		\
				ft_utils.c)



all:			${LIB_LIBFT} ${LIB_PRINTF} ${LIB_GNL} ${NAME}

${NAME}:
				${CC} ${SRCS} ${LIB_PRINTF} ${LIB_LIBFT} ${LIB_GNL} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

# my libraries
$(DIR_LIBFT):
	@git clone https://github.com/yellowcursus42/libft ${DIR_LIBFT}
$(DIR_PRINTF):
	@git clone https://github.com/yellowcursus42/ft_printf ${DIR_PRINTF}
$(DIR_GNL):
	@git clone https://github.com/yellowcursus42/get_next_line ${DIR_GNL}

${LIB_LIBFT}:$(DIR_LIBFT) 
				@echo
				make -C ${DIR_LIBFT}
${LIB_PRINTF}:$(DIR_PRINTF) 
				@echo
				make -C ${DIR_PRINTF}
${LIB_GNL}:$(DIR_GNL) 
				@echo
				make -C ${DIR_GNL}


clean:
				make clean -C ${DIR_LIBFT}
				make clean -C ${DIR_PRINTF}
				make clean -C ${DIR_GNL}
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
				@echo

re:				fclean all


run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re  valgrind run
