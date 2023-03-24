NAME					=	push_swap

LIBFTDIR				=	./libft/
SRCDIR					=	./src/
LIBDIR					=	./lib/
INCLUDEDIR				=	./include/

LIBFTNAME				=	libft.a
SRCFILES				=	push_swap.c 		\
							init.c				\
							stack.c				\
							print.c				\
							operations.c		\
							parse.c				\
							validation.c		\
							util/memory.c		\

SRCS					=	$(addprefix $(SRCDIR), $(SRCFILES))

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror
RM						=	rm -f

all:					$(NAME)

$(NAME):				$(LIBDIR)$(LIBFTNAME) $(SRCS)
							$(CC) $(CFLAGS) $(SRCS) $(LIBDIR)$(LIBFTNAME) -I $(INCLUDEDIR) -o $(NAME)

$(LIBDIR)$(LIBFTNAME):
							$(MAKE) -C $(LIBFTDIR)

clean:
							$(RM) $(NAME)

fclean:					clean
							$(MAKE) fclean -C $(LIBFTDIR)

re:						fclean all

.PHONY:					all clean fclean re

