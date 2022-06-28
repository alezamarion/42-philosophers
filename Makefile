NAME		=	philo

SRC_FILES	=	src/core/philos.c src/core/error_check.c \
				src/utils/ft_atoi.c src/utils/ft_isdigit.c src/utils/ft_memset.c src/utils/philos_atoi.c

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)

OBJ:$(SRC_FILES)
	@mkdir -p obj
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	make -C fclean
	$(RM) $(OBJ)

fclean: clean

re: fclean all

.PHONY: all fclean re bonus


#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.

%.o: %.c
	gcc -Wall -Wextra -Werror -g -lpthread -fsanitize=address

#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como indicação de começo de comando a ser executado
