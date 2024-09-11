NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

SRCS = calculator.c push_operation.c rotate_operation.c split.c stack_utils.c error_free.c operations_both.c \
	   push_swap.c reverse_rotate_operation.c simple_sort.c stack_init.c swap_operation.c
OBJS = calculator.o push_operation.o rotate_operation.o split.o stack_utils.o error_free.o operations_both.o\
	   push_swap.o reverse_rotate_operation.o simple_sort.o stack_init.o swap_operation.o

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $(ARCHIVE) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all
