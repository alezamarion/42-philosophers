# Source, Executable, Includes, Library Defines
NAME	=	philosopher
INCL	=	-I include

SRC_DIR =	./src/core
SRC		=	philos.c error_check.c \

UTIL_DIR =	./src/utils
UTILS	=	ft_atoi.c ft_isdigit.c ft_memset.c philos_atoi.c

OBJ		=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM		=	rm -rf

all:	libfilo bin

libfilo:
	$(CC) -c $(SRC_DIR)/error_check.c $(INCL) -o $(OBJ)/error_check.o
	$(CC) -c $(SRC_DIR)/get_arguments.c $(INCL) -o $(OBJ)/get_arguments.o
	$(CC) -c $(UTIL_DIR)/ft_isdigit.c $(INCL) -o $(OBJ)/ft_isdigit.o
	$(CC) -c $(UTIL_DIR)/ft_memset.c $(INCL) -o $(OBJ)/ft_memset.o
	$(CC) -c $(UTIL_DIR)/philos_atoi.c $(INCL) -o $(OBJ)/philos_atoi.o

bin:
	$(CC) $(SRC_DIR)/philos.c $(OBJ)/*.o $(INCL) -o philosophers


# Compile and Assemble C Source Files into Object Files


# Link all Object Files with external Libraries into Binaries


# Clean Up Objects, Exectuables, Dumps out of source directory
clean: 
	$(RM) $(OBJ)/*.o philosophers

re: clean all

.PHONY: all clean fclean re bonus

#make --debug=b

#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.

#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como 
#	indicação de começo de comando a ser executado
