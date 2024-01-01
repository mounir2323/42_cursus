NAME     					= minishell
CFLAGS   					= -Werror -Wall -Wextra -Iincludes -g
LIBFT 						= ./libft/libft.a			
SRC_DIR  					= src
OBJ_DIR  					= obj

MAIN_SRCS 					= main_minishell.c 
INIT_SRCS					= init_module/init.c
PARSING_SRCS				= parsing_module/parsing.c parsing_module/split_args.c parsing_module/boolean_helpers.c parsing_module/inputs_check.c
BULTIN_SRCS					= bultin_fnc/env_cmd.c bultin_fnc/pwd_cmd.c bultin_fnc/duplicate_env.c bultin_fnc/echo_cmd.c bultin_fnc/utils.c \
								bultin_fnc/export_cmd.c bultin_fnc/unset_cmd.c bultin_fnc/cd_cmd.c bultin_fnc/utils2.c bultin_fnc/utils3.c bultin_fnc/exit_cmd.c
CLEAN_MEMORY_SRCS			= clean_memory_module/clean_memory.c
LEXING_SRCS					= lexing_module/lexing.c lexing_module/helpers.c
SIGNALS_SRCS				= signals/signal.c
EXPENTION_SRCS				= expention_module/expention.c expention_module/helpers.c expention_module/helpers2.c expention_module/helpers3.c expention_module/expend_redir.c
EXECUTION_SRCS				= execution_module/execution.c execution_module/helpers.c execution_module/check_commnd_path.c execution_module/redirections.c execution_module/heredoc/heredoc.c

MAIN_OBJS 					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))
INIT_OBJS 					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(INIT_SRCS))
PARSING_OBJS 				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(PARSING_SRCS))
BULTIN_OBJS					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(BULTIN_SRCS))
CLEAN_MEMORY_OBJS 			= $(patsubst %.c, $(OBJ_DIR)/%.o, $(CLEAN_MEMORY_SRCS))
LEXING_OBJS 				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(LEXING_SRCS))
EXPENTION_OBJS				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(EXPENTION_SRCS))
EXECUTION_OBJS				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(EXECUTION_SRCS))
SIGNALS_OBJS				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SIGNALS_SRCS))

OBJ      = $(MAIN_OBJS) $(INIT_OBJS) $(PARSING_OBJS) $(BULTIN_OBJS) $(CLEAN_MEMORY_OBJS) $(LEXING_OBJS) \
	$(EXPENTION_OBJS) $(EXECUTION_OBJS) $(SIGNALS_OBJS)

READLINE_FLAGS 				= -lreadline

all: install_dependencies $(NAME)

# install_dependencies:
# 	brew install readline

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	@make -C ./libft --silent
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(READLINE_FLAGS) -g

clean:
	@clear
	@make clean -C ./libft --silent
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C ./libft --silent
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re install_dependencies