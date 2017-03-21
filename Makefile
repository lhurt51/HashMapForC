CC =	gcc

FLAG =	-Wall -Wextra -Werror

LFT = 	libft/

LIB =	$(LFT)libft.a

LFLAG =	-L libft/ -lft

NAME =	hashmap

SRCS =	hashmap.c \

FDIR = frame/

OBJS =	$(addprefix $(FDIR), $(SRCS:.c=.o))

all: 	$(NAME)

frame:
		@mkdir $(FDIR)
		@echo "$(FDIR): has been created"

$(NAME): $(OBJS) $(LIB)
		@$(CC) $(FLAG) $(OBJS) $(LFLAG) -o $(NAME)
		@echo "$(NAME): has been created"

frame/%.o: %.c | frame
		@$(CC) $(FLAG) -c $< -o $@

$(LIB):
		@make re -C $(LFT)
		@echo "$(LFT): has been created"

clean:
		@rm -f $(OBJS)
		@rm -rf $(FDIR)
		@echo "$(FDIR) & $(OBJS): have been cleaned"

fclean:	clean
		@/bin/rm -f $(NAME)
		@make fclean -C $(LFT)
		@echo "$(NAME) & $(LFT): have been cleaned"

re: fclean all

.PHONY: all clean fclean re
