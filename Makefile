NAME		=	so_long

SRCS		=	src/main.c get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					src/check_map.c src/err_and_mini_func.c \
					src/button.c src/image.c src/move_up_down.c \
					src/move_left_right.c 

SRCS_BONUS	=	src_bonus/main.c get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					src_bonus/move_left_right.c src_bonus/check_map.c \
					src_bonus/button.c src_bonus/move_up_down.c \
					src_bonus/image.c src_bonus/move_enemy.c \
					src_bonus/err_and_mini_func.c

BONUS_OBJS	=	$(SRCS_BONUS:.c=.o)

OBJS		=	$(SRCS:.c=.o)

HEADER		=	so_long.h

CFLAGS		=	#-Werror -Wall -Wextra

CC			=	gcc

MLX			=	minilibx_linux/libmlx.a

LIBFT		=	./libft/libft.a

FRAMEWORK	=	-framework openGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'

.c :.o	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

#%.o: %.c
#	$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

# $(NAME):	$(OBJS) $(HEADER)
#			 gcc ${MLX} -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 $(OBJS) -o ${NAME}

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(FRAMEWORK) -L./minilibx_linux -lmlx -L./libft/ -lft -o  $(NAME)

$(MLX):
	make -C ./minilibx_linux

$(LIBFT):
	make -C ./libft

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all 

bonus:  $(BONUS_OBJS) $(MLX) $(LIBFT)
		$(CC) $(BONUS_OBJS) $(FRAMEWORK) -L./minilibx_linux -lmlx -L./libft/ -lft -o  $(NAME)

.PHONY: all, clean, fclean, re

norm:
		@norminette ${SRCS} ${SRCS_BONUS} ${HEADER}
		@printf ${GREEN}${CURSIVE}"Norm ok\n"${NONE}
