NAME =	philo 
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f
INC = -Iinclude/
LEAK = valgrind --tool=helgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SRCS_DIR 	= src/
UTILS_DIR 	= utils/
DINNER_DIR 	= dinner/
TIMER_DIR 	= timer/
HANDLE_FREE_DIR = handle_free/
ACTIONS_DIR = actions/
INIT_DIR 	= init/
OBJS_DIR 	= obj/


ARGS = 5 800 200 200 7

FILES = \
	main \
	$(DINNER_DIR)philo $(DINNER_DIR)data \
	$(DINNER_DIR)forks $(DINNER_DIR)supervisor \
	$(HANDLE_FREE_DIR)free_data \
	$(ACTIONS_DIR)eat $(ACTIONS_DIR)sleep \
	$(ACTIONS_DIR)think $(ACTIONS_DIR)die \
	$(UTILS_DIR)ft_long_atoi \
	$(INIT_DIR)init $(INIT_DIR)validate_args \
	$(TIMER_DIR)get_time $(TIMER_DIR)ft_usleep \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(UTILS_DIR)
	@mkdir -p $(OBJS_DIR)$(DINNER_DIR)
	@mkdir -p $(OBJS_DIR)$(HANDLE_FREE_DIR)
	@mkdir -p $(OBJS_DIR)$(ACTIONS_DIR)
	@mkdir -p $(OBJS_DIR)$(TIMER_DIR)
	@mkdir -p $(OBJS_DIR)$(INIT_DIR)

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
