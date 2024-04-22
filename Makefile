CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

NAME	=	libftprintf.a
INCLUDE	= 	pintf.h

SRC		=	ft_printf.c			\
			ft_printsimp.c			\
			ft_hexadecimal.c	\
			ft_printpointer.c

OBJ		=	${SRC:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo "Compiling .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Done !"

clean:
	@echo "Remove .o  ..."
	${RM} ${OBJ}
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	${RM} $(NAME)
	@echo "Done !"

re: fclean all

