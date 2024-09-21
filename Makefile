COLOR_RESET = \033[0m
COLOR_RED = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_YELLOW = \033[1;33m
COLOR_BLUE = \033[1;34m
COLOR_CYAN = \033[1;36m

CC				= cc

CFLAGS 			= -Wall -Wextra -Werror -g3

INCLUDEPATH		= ./includes/

SRCPATH 		= ./srcs/

OBJDIR 			= ./obj/

DEPDIR 			= ./dep/

SRCNAME			= main.c \
				  parse.c check_args.c \
				  create_and_init_data.c init_mutex.c init_array_mutex.c \
				  create_array.c \
				  execute.c philosopher_actions.c \
				  print_error.c print_state.c \
				  utils.c execute_utils.c parse_utils.c philosopher_actions_utils.c \
				  clean_memory.c destroy_mutex.c destroy_partial_mutex.c destroy_array_mutex.c


SRCS = $(addprefix $(SRCPATH), $(SRCNAME))

OBJS = $(patsubst $(SRCPATH)%.c, $(OBJDIR)%.o, $(SRCS))

DEPS = $(patsubst $(OBJDIR)%.o, $(DEPDIR)%.d, $(OBJS))

NAME = philo

all: $(OBJDIR) $(DEPDIR) $(NAME)

$(OBJDIR) $(DEPDIR):
	@mkdir -p $(OBJDIR) $(DEPDIR)

$(OBJDIR)%.o: $(SRCPATH)%.c
	@$(CC) $(CFLAGS) -I$(INCLUDEPATH) -MMD -MP -c $< -o $@
	@echo "$(COLOR_GREEN)Compilation of  $(COLOR_RESET)$(COLOR_BLUE)$<$(COLOR_RESET)$(COLOR_GREEN)  into  $(COLOR_BLUE)$@$(COLOR_RESET)$(COLOR_GREEN)  was successful$(COLOR_RESET)"
	
$(NAME): $(OBJS)
	@echo "$(COLOR_RED)Executable $(NAME) created successfully!$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@mv obj/*.d dep/

-include $(DEPS)

clean:
	@rm -rf obj dep
	@echo "$(COLOR_YELLOW)Cleaning successfully$(COLOR_RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(COLOR_YELLOW)Full Cleaning successfully$(COLOR_RESET)"

debug: CFLAGS += -fsanitize=address
debug: fclean all

re: fclean all

.PHONY: all clean fclean re debug