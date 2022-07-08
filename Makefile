# Source, Executable, Includes, Library Defines
NAME	=	philosophers
INCL	=	-I include

SRC_DIR =	./src
SRC		=	error_check.c

UTIL_DIR =	./utils
UTILS	=	print_status.c utils_dinner.c utils.c

OBJ		=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM		=	rm -rf

all:	libfilo bin

libfilo:
	$(CC) -c $(CFLAGS) $(SRC_DIR)/error_check.c $(INCL) -o $(OBJ)/error_check.o
	$(CC) -c $(CFLAGS) $(UTIL_DIR)/print_status.c $(INCL) -o $(OBJ)/print_status.o
	$(CC) -c $(CFLAGS) $(UTIL_DIR)/utils_dinner.c $(INCL) -o $(OBJ)/utils_dinner.o
	$(CC) -c $(CFLAGS) $(UTIL_DIR)/utils.c $(INCL) -o $(OBJ)/utils.o

bin:
	$(CC) $(CFLAGS) $(SRC_DIR)/philosophers.c $(OBJ)/*.o $(INCL) -o philosophers

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
