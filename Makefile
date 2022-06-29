# Source, Executable, Includes, Library Defines
NAME	=	philos
INCL	=	include/philosophers.h
SRC		=	src/core/philos.c src/core/error_check.c \
			src/utils/ft_atoi.c src/utils/ft_isdigit.c src/utils/ft_memset.c src/utils/philos_atoi.c
#OBJ		:=	$(SRC:.c=.o)
#LIBS   =	-lpthread


# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
#LIBPATH =	-L.
#LDFLAGS =	-o $(OBJ) #$(LIBPATH) $(LIBS)
#CFDEBUG =	-ansi -pedantic -Wall -g -DDEBUG $(LDFLAGS)
RM		=	rm -f

# Compile and Assemble C Source Files into Object Files
%.o:		%.c
			$(CC) -c $(CFLAGS) $*.c

# Link all Object Files with external Libraries into Binaries
$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) 

# Objects depend on these Libraries
$(OBJ):		$(INCL)

# Create a gdb/dbx Capable Executable with DEBUG flags turned on
#debug:
#		$(CC) $(CFDEBUG) $(SRC)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
		$(RM) $(OBJ) $(EXE) core a.out

.PHONY: all clean fclean re bonus


#make --debug=b

#$@ relaciona-se com o alvo e $^ relaciona-se com todos pŕe-requisitos.


#target	:	prerequisites
#	recipe
# target: nome da ação que deseja executar ou usualmente o nome do arquivo que se queira produzir
# prerequisitos são os arquivos que são usados como input para criar o target
# receita é a ação que o comando make realiza - o TAB antes da receita é interpretado pelo make como indicação de começo de comando a ser executado
