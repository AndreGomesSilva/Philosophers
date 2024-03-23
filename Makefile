NAME =	philo 
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f
INC = -Iinclude/
LEAK = valgrind --tool=helgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SRCS_DIR 	= src/
UTILS_DIR 	= utils/
PHILO_DIR 	= philo/
HANDLE_FREE_DIR = handle_free/
OBJS_DIR 	= obj/


ARGS = 5 800 200 200 7

FILES = \
	main \
	init \
	$(PHILO_DIR)philo \
	$(HANDLE_FREE_DIR)free_data \
	$(UTILS_DIR)ft_long_atoi $(UTILS_DIR)ft_usleep \
	$(UTILS_DIR)ft_error $(UTILS_DIR)validate_args \
	$(UTILS_DIR)get_time \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(UTILS_DIR)
	@mkdir -p $(OBJS_DIR)$(PHILO_DIR)
	@mkdir -p $(OBJS_DIR)$(HANDLE_FREE_DIR)

play: re
	./$(NAME) $(ARGS)	

val: re
	$(LEAK) ./$(NAME) $(ARGS)

clean:
	$(RM) -r $(OBJS_DIR) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
