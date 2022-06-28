NAME		=	philos

SRC_DIR 	=	src
INCLUDES 	=	include
HEADERS		:=	$(INCLUDES)/philosophers.h
INCLUDES	:=	$(addprefix -I, $(INCLUDES))

SRC_FILES	=	core/philos.c core/error_check.c \
				utils/ft_atoi.c utils/ft_isdigit.c utils/ft_memset.c utils/philos_atoi.c

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR		= obj
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM			=	rm -rf

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $@
	@echo "\033[32mDone!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(OBJ_DIR) fclean

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
	@echo "\033[32mExecutable and objects cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus



#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.


#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como indicação de começo de comando a ser executado
