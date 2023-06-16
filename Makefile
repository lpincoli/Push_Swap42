CC = gcc

NAME = libpushswap.a

SRC := ft_barbarian_chunk.c ft_check_args.c ft_dividetimpera.c ft_eldritch_sort.c ft_find_closer.c \
		ft_findmin_max.c ft_op_p.c ft_op_r.c ft_op_rr.c ft_op_s.c ft_push_swap.c ft_quicksort.c
		
BNS = ft_checker_bonus.c ft_cop_p_bonus.c ft_cop_r_bonus.c ft_cop_rr_bonus.c ft_cop_s_bonus.c \
		ft_read_and_do_bonus.c ft_check_args_bonus.c
		
BNS := $(addprefix bonus/, $(BNS))

OBJ_S = $(SRC:.c=.o)

OBJ_B = $(BNS:.c=.o)

CFLAG = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ_S)
	cd src && make
	@ar -rcs $@ $^ src/libft.a
	@echo Libreria compilata!
	gcc $(CFLAG) $@ src/libft.a -o push_swap
%.o:%.c
	@$(CC) -c -g $(CFLAG) -I. $< -o $@

clean: 
	@/bin/rm -f *.o */*.o

fclean: clean
	cd src && make fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libpushswapbonus.a
	@/bin/rm -f checker
	@/bin/rm -f push_swap
	@echo File .o e libreria rimossi!

re: fclean all

bonus: $(OBJ_B)
	cd src && make
	ar -rcs libpushswapbonus.a $^
	gcc $(CFLAG) libpushswapbonus.a src/libft.a -o checker
run: all
	@gcc $(CFLAG) -g ft_checker.c $(NAME) -o checker
debug: re 
	gcc -g ft_push_swap.c $(NAME)
	gdb --args ./a.out $(ARGS)
	
.PHONY: all clean fclean re run
