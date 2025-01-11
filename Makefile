CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = -lft -Llibft -lreadline
PREFIX = 
PREPROC_DEFINES = 

SOURCE_F = sources
TEST_F = tests

EXTERNAL_OPTIONS_NAMES = opts.c opts_fill.c pre_post.c
EXTERNAL_OPTIONS_F = external_options
EXTERNAL_OPTIONS_SRCS = $(addprefix $(EXTERNAL_OPTIONS_F)/, $(EXTERNAL_OPTIONS_NAMES))

INTERNAL_SETTINGS_NAMES = finalize.c param_init.c param_get_envvars.c g_interrupt_flag.c
INTERNAL_SETTINGS_F = internal_settings
INTERNAL_SETTINGS_SRCS = $(addprefix $(INTERNAL_SETTINGS_F)/, $(INTERNAL_SETTINGS_NAMES))

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_00.c mock_01.c mock_02.c mock_03.c mock_04.c mock_05.c mock_06.c mock_07.c mock_08.c mock_09.c mock_10.c mock_11.c mock_12.c mock_13.c mock_14.c mock_15.c mock_16.c mock_17.c mock_18.c mock_19.c mock_20.c mock_21.c mock_22.c mock_23.c mock_24.c mock_25.c mock_26.c mock_27.c mock_28.c mock_29.c mock_30.c mock_31.c mock_32.c mock_33.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

COMMANDS_NAMES = option_cd.c option_echo.c option_env.c option_exit.c option_export.c option_external.c option_pwd.c option_unset.c get_envvars_for_execve.c
COMMANDS_F = commands
COMMANDS_SRCS = $(addprefix $(COMMANDS_F)/,$(COMMANDS_NAMES))

SPLIT_NAMES = ft_split_str.c calc_tokens.c locate_plain_token.c handle_quotes.c copy_token.c if_empty_string.c
SPLIT_F = split
SPLIT_SRCS = $(addprefix $(SPLIT_F)/, $(SPLIT_NAMES))

TOKENIZING_NAMES = tokenize_cmd.c init_structs.c tokenize_cmd_utils.c
TOKENIZING_F = tokenizing
TOKENIZING_SRCS = $(addprefix $(TOKENIZING_F)/, $(TOKENIZING_NAMES))

TREE_MAKE_NAMES = tokens_to_tree.c is_closing_parenthesis.c is_opening_parenthesis.c is_operator.c is_redirection.c process_cmd_and_flag.c process_parentheses.c process_oprator.c
TREE_MAKE_F = tree_make
TREE_MAKE_SRCS = $(addprefix $(TREE_MAKE_F)/, $(TREE_MAKE_NAMES))

TREE_EXPANSION_NAMES = expand_tree.c
TREE_EXPANSION_F = tree_expansion
TREE_EXPANSION_SRCS = $(addprefix $(TREE_EXPANSION_F)/, $(TREE_EXPANSION_NAMES))

COMMAND_EXPANSION_NAMES = substitute_envvars.c expand.c
COMMAND_EXPANSION_F = command_expansion
COMMAND_EXPANSION_SRCS = $(addprefix $(COMMAND_EXPANSION_F)/, $(COMMAND_EXPANSION_NAMES))

EXECUTION_NAMES = exec_text_tree.c exec_text_tree_node.c exec_text_tree_controls.c redirections.c pipes.c files.c is_pipe.c is_redir.c
EXECUTION_F = execution
EXECUTION_SRCS = $(addprefix $(EXECUTION_F)/, $(EXECUTION_NAMES))

COMMANDS_NAMES = option_cd.c option_echo.c option_env.c option_exit.c option_export.c option_external.c option_pwd.c option_unset.c get_envvars_for_execve.c w_execve.c
COMMANDS_F = commands
COMMANDS_SRCS = $(addprefix $(COMMANDS_F)/,$(COMMANDS_NAMES))

SRC_NAMES = $(EXTERNAL_OPTIONS_SRCS) $(INTERNAL_SETTINGS_SRCS) input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS) $(SPLIT_SRCS) $(TOKENIZING_SRCS) $(TREE_MAKE_SRCS) $(TREE_EXPANSION_SRCS) $(COMMAND_EXPANSION_SRCS) $(EXECUTION_SRCS) $(COMMANDS_SRCS)
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

TEST_NAMES = input_to_text_tree_test.c ft_split_str_test.c tokenize_cmd_test.c unit_tests.c e2e_tests.c expand_tree_test.c get_envvars_test.c
TEST_ENDPOINT_NAME = main_test.c
TEST_SRCS = $(addprefix $(TEST_F)/, $(TEST_NAMES))
TEST_ENDPOINT_SRC = $(addprefix $(TEST_F)/, $(TEST_ENDPOINT_NAME))
TEST_FNAME = $(TEST_F)/test

TEST_TOOL_NAMES = tool_print_environment.c
TEST_TOOL_SRCS = $(addprefix $(TEST_F)/, $(TEST_TOOL_NAMES))
TEST_TOOL_FNAME = $(TEST_F)/tool_print_environment

OBJ_F = build/
TEST_OBJ_F = $(OBJ_F)tests/

OBJS = $(addprefix $(OBJ_F), $(SRC_NAMES:.c=.o))
TEST_OBJS = $(addprefix $(TEST_OBJ_F), $(TEST_NAMES:.c=.o))
ENDPOINT_OBJ = $(OBJ_F)$(ENDPOINT_NAME:.c=.o)
TEST_ENDPOINT_OBJ = $(TEST_OBJ_F)$(TEST_ENDPOINT_NAME:.c=.o)
TEST_TOOL_OBJS = $(addprefix $(TEST_OBJ_F), $(TEST_TOOL_NAMES:.c=.o))
INCLUDES = -I . -I libft

DIRS = $(EXTERNAL_OPTIONS_F) $(INTERNAL_SETTINGS_F) $(INPUT_TO_TEXT_TREE_MOCK_F) $(TOKENIZING_F) $(TREE_MAKE_F) $(TREE_EXPANSION_F) $(COMMAND_EXPANSION_F) $(EXECUTION_F) $(COMMANDS_F) $(SPLIT_F)

OBJ_DIRS = $(addprefix $(OBJ_F), $(DIRS))

vpath %.c $(SOURCE_F) $(SOURCE_F)/$(COMMANDS_F) $(SOURCE_F)/$(INPUT_TO_TEXT_TREE_MOCK_F) $(SOURCE_F)/$(TREE_MAKE_F)\
			$(SOURCE_F)/$(TOKENIZING_F)

all: pre $(NAME)

$(OBJ_DIRS):
	$(PREFIX)mkdir -p $(OBJ_DIRS)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $(OBJS) $(ENDPOINT_OBJ) -o $@ $(LINK_FLAGS)

$(OBJ_F)%.o: %.c $(OBJ_DIRS)
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

$(TEST_OBJ_F):
	$(PREFIX)mkdir -p $(TEST_OBJ_F)

$(TEST_TOOL_FNAME): $(TEST_TOOL_OBJS)
	$(PREFIX)$(CC) $(TEST_TOOL_OBJS) -o $(TEST_TOOL_FNAME) $(LINK_FLAGS)

$(TEST_OBJ_F)%.o: $(TEST_F)/%.c $(TEST_OBJ_F)
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

test_trapped:
	$(PREFIX)make PREPROC_DEFINES="$(PREPROC_DEFINES) -DFT_CALLOC_IF_TRAPPED" test

test: $(OBJ_DIRS) $(TEST_OBJ_F) $(OBJS) $(TEST_OBJS) $(TEST_ENDPOINT_OBJ) $(TEST_TOOL_FNAME)
	$(PREFIX)$(CC) $(OBJS) $(TEST_OBJS) $(TEST_ENDPOINT_OBJ) -o $(TEST_FNAME) $(LINK_FLAGS)

preclean:
	$(PREFIX)cd libft && make clean

prefclean:
	$(PREFIX)cd libft && make fclean

pretestfclean:
	$(PREFIX)cd libft && make testfclean

prere:
	$(PREFIX)cd libft && make re

clean: testclean
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJ) $(TANIA_ENDPOINT_OBJ)
	$(PREFIX)@if [ -d $(OBJ_F) ]; then rm -rf $(OBJ_F); fi

fclean: clean testfclean
	$(PREFIX)rm -f $(NAME)

re: fclean all

testclean:
	$(PREFIX)rm -f $(TEST_OBJS) $(TEST_ENDPOINT_OBJ) $(TEST_TOOL_OBJS)
	$(PREFIX)@if [ -d $(TEST_OBJ_F) ]; then rm -rf $(TEST_OBJ_F); fi

testfclean: testclean
	$(PREFIX)rm -f $(TEST_FNAME) $(TEST_TOOL_FNAME)

retest: testfclean test

memcheck:
	$(PREFIX)valgrind --suppressions=tests/valgrind.supp --leak-check=full --show-leak-kinds=all $(TEST_FNAME)

memcheck_interactive:
	$(PREFIX)valgrind --suppressions=tests/valgrind.supp --leak-check=full --show-leak-kinds=all ./$(NAME) --interactive

fulltest_common:
	$(PREFIX)cd libft && make fulltest_trapped
	$(PREFIX)make fclean testfclean
	$(PREFIX)cd sources && norminette
	$(PREFIX)make all_trapped

fulltest_vania: fulltest_common
	$(PREFIX)make PREPROC_DEFINES="$(PREPROC_DEFINES) -DVANIA" test_trapped memcheck

fulltest: fulltest_common
	$(PREFIX)make test_trapped memcheck

PHONY: all pre clean fclean re test fulltest testclean testfclean retest memcheck memcheck_interactive fulltest_common fulltest_vania tania vania minivania all_trapped

########################################

TANIA_OBJ_F = $(OBJ_F)tania/

TANIA_ENDPOINT_NAME = tania_main.c
TANIA_ENDPOINT_SRCS = $(addprefix $(SOURCE_F)/,$(TANIA_ENDPOINT_NAME))
TANIA_ENDPOINT_OBJ = $(TANIA_OBJ_F)$(TANIA_ENDPOINT_NAME:.c=.o)

$(TANIA_OBJ_F):
	$(PREFIX)mkdir -p $(TANIA_OBJ_F)

$(TANIA_OBJ_F)%.o: $(SOURCE_F)/%.c $(TANIA_OBJ_F)
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

tania: $(OBJ_DIRS) $(TANIA_OBJ_F) $(OBJS) $(TANIA_ENDPOINT_OBJ)
	$(PREFIX)$(CC) $(OBJS) $(TANIA_ENDPOINT_OBJ) -o $(NAME) $(LINK_FLAGS)

########################################

all_trapped:
	$(PREFIX)make PREPROC_DEFINES="$(PREPROC_DEFINES) -DFT_CALLOC_IF_TRAPPED" all

vania:
	$(PREFIX)cd libft && make fulltest_trapped_nonorm
	$(PREFIX)make fclean testfclean
	$(PREFIX)make minivania

minivania:
	$(PREFIX)make all test && ./$(TEST_FNAME)
run:
	$(PREFIX)./minishell --debug 136 --command $(CMD)
debug:
	$(PREFIX)gdbtui --args ./minishell --debug 136 --command $(CMD)
mem:
	$(PREFIX)valgrind --suppressions=tests/valgrind.supp --child-silent-after-fork=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./minishell --debug 136 --command $(CMD)