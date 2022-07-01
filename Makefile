# Source, Executable, Includes, Library Defines
NAME	=	philosopher
INCL	=	include/philosophers.h
SRC		=	src/core/philos.c src/core/error_check.c \
			src/utils/ft_atoi.c src/utils/ft_isdigit.c src/utils/ft_memset.c src/utils/philos_atoi.c
OBJ		=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM		=	rm -rf

all:
	$(CC) -c src/core/error_check.c -I $(INCL) -o $(OBJ)/error_check.o
	$(CC) -c src/utils/ft_atoi.c -I $(INCL) -o $(OBJ)/ft_atoi.o
	$(CC) -c src/utils/ft_isdigit.c -I $(INCL) -o $(OBJ)/ft_isdigit.o
	$(CC) -c src/utils/ft_memset.c -I $(INCL) -o $(OBJ)/ft_memset.o
	$(CC) -c src/utils/philos_atoi.c -I $(INCL) -o $(OBJ)/philos_atoi.o

	$(CC) src/core/philos.c $(OBJ)/*.o -I $(INCL) -o philosophers

#obj/error_check.o obj/ft_atoi.o obj/ft_isdigit.o obj/ft_memset.o obj/philos_atoi.o obj/philos.o -o philosophers
#	$(CC) $(OBJ)/*.o -I $(INCL) -o philosophers

# Compile and Assemble C Source Files into Object Files


# Link all Object Files with external Libraries into Binaries



# Clean Up Objects, Exectuables, Dumps out of source directory
clean: 
	$(RM) $(OBJ)/*.o philosophers

.PHONY: all clean fclean re bonus

#make --debug=b

#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.

#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como 
#	indicação de começo de comando a ser executado
