##
## Makefile for Makefile in /home/blanch_p/rendu/Infographie/gfx_incendie/fire
## 
## Made by Alexandre Blanchard
## Login   <blanch_p@epitech.net>
## 
## Started on  Sun Dec  6 16:56:26 2015 Alexandre Blanchard
## Last update Tue Jun  7 15:20:48 2016 Alexandre Blanchard
##

NAME1		=	bsq

SRC1		=	src/main.c \
			src/check.c \
			src/change.c \
			src/count.c \
			src/tab.c \
			src/replace.c \

OBJ1		=	$(SRC1:.c=.o)


$(NAME1):	$(OBJ1)
		gcc $(OBJ1) libmy.a -o $(NAME1)


all:		$(NAME1)

clean:
		rm -f $(OBJ1)

fclean:		clean
		rm -f $(NAME1)

re:		fclean all
