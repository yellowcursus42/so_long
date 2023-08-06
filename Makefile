NAME			= so_long

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

SRCS_DIR		= ./src/

# all except header file.
SRCS 			= $(addprefix $(SRCS_DIR),\
					free_memory.c\
					game_init.c\
					handle_close.c\
					handle_input.c\
					map_check.c\
					map_init.c\
					render.c\
					so_long.c\
					utils.c\
					)

all:			${LIB_LIBFT} ${LIB_PRINTF} ${LIB_GNL} ${NAME}

${NAME}:${LIB_LIBFT} ${LIB_PRINTF} ${LIB_GNL}
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
				make fclean -C ${DIR_LIBFT}
				make fclean -C ${DIR_PRINTF}
				make fclean -C ${DIR_GNL}
				rm -f ${NAME}
				@echo

re:				fclean all


run:			${NAME}
				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re run
