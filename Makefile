NAME		=	philosophers

SRC_FILES	=	thread.c
SRC_DIR		=	src

INCLUDES	=	includes
INCLUDES 	:=	$(addprefix -I, $(INCLUDES))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g -lpthread -fsanitize=address
RM			=	rm -rf

OBJS_DIR	=	obj
OBJS		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC_FILES:.c=.o))

$(NAME): all
$(NAME): $(OBJ)
@-$(CC) $(CFLAGS) $(OBJS)

clean:
	make -C fclean
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all fclean re bonus
