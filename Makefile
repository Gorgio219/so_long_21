NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)
MLXFLAGS= -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER	= so_long.h
CC		= gcc
RM		= rm -rf

SRC		= 	main_sl.c\
			utils.c\
			get_next_line.c\
			checker.c\
			hook.c\
			imeg.c\

OBJ		= $(SRC:%.c=%.o)

LIBDIR 	= libft
MLXDIR	= mlx

MLX		= libmlx*
LIBFT	= libft.a

.PHONY		:	all re clean fclean

all			: $(NAME)

$(NAME)		: $(OBJ)
			@make -C $(LIBDIR)/
			@make -C $(MLXDIR)/
			$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS) -Llibft -lft

%.o		: %.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@ -I

clean		:
			$(RM) $(OBJ)
			@make clean -C $(LIBDIR)/

fclean		: clean
			$(RM) $(NAME)
			@make fclean -C $(LIBDIR)/
			@make clean -C $(MLXDIR)/

re			: fclean all

