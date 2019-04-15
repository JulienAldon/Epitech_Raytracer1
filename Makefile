##
## Makefile for projet in /home/julien.aldon/delivery/test/prep_my_repo
## 
## Made by Julien Aldon
## Login   <julien.aldon@epitech.net>
## 
## Started on  Wed Dec  7 11:33:30 2016 Julien Aldon
## Last update Thu Mar  9 15:50:25 2017 Julien Aldon
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -Werror
LDLIBS +=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lm
CFLAGS	+=	-Iinclude

NAME	=	Raytracer1

SRCS	=	src/main.c			\
		src/my_draw.c			\
		src/sphere.c			\
		src/plane.c				\
		src/cone.c				\
		src/calc_dir_vector.c	\
		src/cylinder.c			\
		src/translate.c			\
		src/vector_light.c		\
		src/my_put_pixel.c		\
		src/init.c				\
		src/light.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
