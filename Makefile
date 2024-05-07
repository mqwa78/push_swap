SRC	=	./src/main.c
SRC	+=	./src/push_swap.c
SRC	+=	./src/best_elem.c
SRC	+=	./src/biggy_sort.c
SRC	+=	./src/count_op.c
SRC	+=	./src/create_list_tools.c
SRC	+=	./src/create_list.c
SRC	+=	./src/fill_stack.c
SRC	+=	./src/free_and_error.c
SRC	+=	./src/list_manip.c
SRC	+=	./src/list_manip2.c
SRC	+=	./src/list_manip3.c
SRC	+=	./src/min_max.c
SRC	+=	./src/push.c
SRC	+=	./src/rev_rotate.c
SRC	+=	./src/rotate.c
SRC	+=	./src/setup_and_reset.c
SRC	+=	./src/swap.c
SRC	+=	./src/do_instructions.c

BONUS_SRC	=	./bonus/checker_bonus.c
BONUS_SRC	+=	./bonus/create_list_bonus.c
BONUS_SRC	+=	./bonus/create_list_tools_bonus.c
BONUS_SRC	+=	./bonus/free_and_error_bonus.c
BONUS_SRC	+=	./bonus/gnl_bonus.c
BONUS_SRC	+=	./bonus/list_manip_bonus.c
BONUS_SRC	+=	./bonus/list_manip2_bonus.c
BONUS_SRC	+=	./bonus/main_bonus.c
BONUS_SRC	+=	./bonus/push_bonus.c
BONUS_SRC	+=	./bonus/rev_rotate_bonus.c
BONUS_SRC	+=	./bonus/rotate_bonus.c
BONUS_SRC	+=	./bonus/swap_bonus.c

OBJ	=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)
NAME	=	push_swap
NAME_BONUS	= checker
CC	=	cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS += -I includes/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

bonus : $(BONUS_OBJ)
		$(CC) $(BONUS_OBJ) $(CFLAGS) -o $(NAME_BONUS)

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)


re : fclean all

.PHONY : all clean fclean re
