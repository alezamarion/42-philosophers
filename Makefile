NAME		=	thread

SRC_FILES	=	src/thread.c

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -lpthread -fsanitize=address
RM			=	rm -rf

OBJ:$(SRC_FILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	make -C fclean
	$(RM) $(NAME)

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
