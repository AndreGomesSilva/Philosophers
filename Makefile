NAME =	philo 
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -Iinclude/
LEAK = valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
SRCS_DIR 	= src/
OBJS_DIR 	= obj/

FILES = \
	main \
	init \
	ft_long_atoi \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
