CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = -lft -Llibft -lreadline
PREFIX =
MOCK_FLAG =

SOURCE_F = sources
TEST_F = tests

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_0.c mock_1.c mock_2.c mock_3.c mock_4.c mock_5.c mock_6.c mock_7.c mock_8.c mock_9.c mock_10.c mock_11.c mock_12.c mock_13.c mock_14.c mock_15.c mock_16.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

COMMANDS_NAMES = option_cd.c option_echo.c option_env.c option_exit.c option_export.c option_external.c option_pwd.c option_unset.c get_envvars_for_execve.c
COMMANDS_F = commands
COMMANDS_SRCS = $(addprefix $(COMMANDS_F)/,$(COMMANDS_NAMES))

PARSING_NAMES = parse_command.c parse_commands_utils.c
PARSING_F = parsing
PARSING_SRCS = $(addprefix $(PARSING_F)/, $(PARSING_NAMES))

TREE_MAKE_NAMES = tokens_to_tree.c tokens_type.c
TREE_MAKE_F = tree_make
TREE_MAKE_SRCS =  $(addprefix $(TREE_MAKE_F)/, $(TREE_MAKE_NAMES))

SRC_NAMES = finalize.c param_init.c param_get_envvars.c wrappers.c input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS) exec_text_tree.c exec_text_tree_node.c $(COMMANDS_SRCS) $(PARSING_SRCS) w_execve.c $(TREE_MAKE_SRCS)
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

TEST_NAMES = input_to_text_tree_test.c parse_command_test.c tokens_to_tree_test.c
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

DIRS = $(COMMANDS_F) $(INPUT_TO_TEXT_TREE_MOCK_F) $(PARSING_F) $(TREE_MAKE_F)

OBJ_DIRS = $(addprefix $(OBJ_F), $(DIRS))

vpath %.c $(SOURCE_F) $(SOURCE_F)/$(COMMANDS_F) $(SOURCE_F)/$(INPUT_TO_TEXT_TREE_MOCK_F) $(SOURCE_F)/$(TREE_MAKE_F)

all: pre $(NAME)

$(OBJ_DIRS):
	$(PREFIX)mkdir -p $(OBJ_DIRS)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $(OBJS) $(ENDPOINT_OBJ) -o $@ $(LINK_FLAGS)

$(OBJ_F)%.o: %.c $(OBJ_DIRS)
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(TEST_OBJ_F):
	$(PREFIX)mkdir -p $(TEST_OBJ_F)

$(TEST_TOOL_FNAME): $(TEST_TOOL_OBJS)
	$(PREFIX)$(CC) $(TEST_TOOL_OBJS) -o $(TEST_TOOL_FNAME) $(LINK_FLAGS)

$(TEST_OBJ_F)%.o: $(TEST_F)/%.c $(TEST_OBJ_F) $(TEST_ENDPOINT_OBJ)
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

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
	$(PREFIX)@if [ -d $(OBJ_F) ]; then $(PREFIX)rm -rf $(OBJ_F); fi

fclean: clean testfclean
	$(PREFIX)rm -f $(NAME)

re: fclean all

testclean:
	$(PREFIX)rm -f $(TEST_OBJS) $(TEST_ENDPOINT_OBJ) $(TEST_TOOL_OBJS)
	$(PREFIX)@if [ -d $(TEST_OBJ_F) ]; then $(PREFIX)rm -rf $(TEST_OBJ_F); fi

testfclean: testclean
	$(PREFIX)rm -f $(TEST_FNAME) $(TEST_TOOL_FNAME)

pretestfclean:
	$(PREFIX)cd libft && make testfclean

retest: testfclean test

memcheck:
	$(PREFIX)valgrind --leak-check=full --show-leak-kinds=all $(TEST_FNAME)

fulltest:
	$(PREFIX)cd libft && make fulltest
	$(PREFIX)make fclean testfclean
	$(PREFIX)cd sources && norminette
	$(PREFIX)make vania test memcheck

PHONY: all pre clean fclean re test fulltest testclean testfclean retest tania vania

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

vania: MOCK_FLAG += -DMOCK_TANIA
vania: all
