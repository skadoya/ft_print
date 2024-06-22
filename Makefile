NAME  = libftprintf.a
SRCS  = ft_printf.c sub.c

OBJS  = $(SRCS:.c=.o)

CC    = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME) 

#$(NAME): $(OBJS)
#		ar rcs $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@
#		ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 
	make fclean -C ./libft

fclean: clean
		rm -f $(NAME) 
		# make -C libft/libft.a fclean

re: fclean all

.PHONY: all re clean fclean