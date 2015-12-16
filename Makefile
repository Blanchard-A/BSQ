##
## Makefile for Makefile in /home/blanch_p/rendu/Infographie/gfx_incendie/fire
## 
## Made by Alexandre Blanchard
## Login   <blanch_p@epitech.net>
## 
## Started on  Sun Dec  6 16:56:26 2015 Alexandre Blanchard
## Last update Wed Dec 16 14:13:01 2015 Alexandre Blanchard
##

NAME1		=	bsq

SRC1		=	main.c \
			check.c \
			change.c \
			count.c \
			tab.c \
			replace.c \


OBJ1		=	$(SRC1:.c=.o)


$(NAME1):	$(OBJ1)
		gcc $(OBJ1) libmy.a -o $(NAME1)


all:		$(NAME1)

clean:
		rm -f $(OBJ1)

fclean:		clean
		rm -f $(NAME1)

re:		fclean all
