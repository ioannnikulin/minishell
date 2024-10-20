CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = -lft -Llibft -lreadline
PREFIX =
MOCK_FLAG =

SOURCE_F = sources
TEST_F = tests

COMMANDS_NAMES = option_cd.c option_echo.c option_env.c option_exit.c option_export.c option_external.c option_pwd.c option_unset.c get_envvars_for_execve.c
COMMANDS_F = commands
COMMANDS_SRCS = $(addprefix $(COMMANDS_F)/,$(COMMANDS_NAMES))

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_0.c mock_1.c mock_2.c mock_3.c mock_4.c mock_5.c mock_6.c mock_7.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

PARSING_NAMES = parse_command.c parse_commands_utils.c
PARSING_F = parsing
PARSING_SRCS = $(addprefix $(PARSING_F)/, $(PARSING_NAMES))

TREE_CREATION_NAMES = create_text_tree.c
TREE_CREATION_F = tree_creation
TREE_CREATION_SRCS = $(addprefix $(TREE_CREATION_F)/, $(TREE_CREATION_NAMES))

SRC_NAMES = finalize.c param_init.c param_get_envvars.c wrappers.c input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS) exec_text_tree.c exec_text_tree_node.c $(COMMANDS_SRCS) $(PARSING_SRCS) $(TREE_CREATION_SRCS)
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

OBJ_F = build/
OBJS = $(addprefix $(OBJ_F), $(SRC_NAMES:.c=.o))
ENDPOINT_OBJ = $(OBJ_F)$(ENDPOINT_NAME:.c=.o)
INCLUDES = -I . -I libft

TEST_NAMES = main_test.c input_to_text_tree_test.c parse_command_test.c
TEST_SRCS = $(addprefix $(TEST_F)/, $(TEST_NAMES))
TEST_OBJS = $(addprefix $(OBJ_F), $(TEST_NAMES:.c=.o))
TEST_FNAME = $(TEST_F)/test

DIRS = $(COMMANDS_F) $(INPUT_TO_TEXT_TREE_MOCK_F) $(PARSING_F) $(TREE_CREATION_F)
OBJ_DIRS = $(addprefix $(OBJ_F), $(DIRS))

all: pre $(OBJ_DIRS) $(NAME)

$(OBJ_DIRS):
	$(PREFIX)mkdir -p $(OBJ_DIRS)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $^ -o $@ $(LINK_FLAGS)

$(OBJ_F)%.o: $(SOURCE_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(OBJ_F)%.o: $(COMMANDS_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(OBJ_F)%.o: $(INPUT_TO_TEXT_TREE_MOCK_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(OBJ_F)%.o: $(PARSING_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(OBJ_F)%.o: $(TEST_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

preclean:
	$(PREFIX)cd libft && make clean

prefclean:
	$(PREFIX)cd libft && make fclean

prere:
	$(PREFIX)cd libft && make re

clean:
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJ) $(TANIA_ENDPOINT_OBJ) $(VANIA_ENDPOINT_OBJ)
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJ) $(VANIA_ENDPOINT_OBJ) $(TANIA_ENDPOINT_OBJ)

fclean: clean
	$(PREFIX)rm -f $(NAME)
	$(PREFIX)rm -f $(ENDPOINT_OBJ)
	$(PREFIX)rm -f $(ENDPOINT_OBJ)

re: fclean all

test: $(OBJS) $(TEST_OBJS)
	$(PREFIX)$(CC) $^ -o $(TEST_FNAME) $(LINK_FLAGS)

testclean:
	$(PREFIX)rm -f $(TEST_OBJS)

testfclean: testclean
	$(PREFIX)rm -f $(TEST_FNAME)

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

PHONY: all pre clean fclean re test fulltest testclean testfclean retest

########################################

TANIA_ENDPOINT = sources/tania_main.c
TANIA_ENDPOINT_OBJ = $(OBJ_F)$(TANIA_ENDPOINT:.c=.o)

$(TANIA_ENDPOINT_OBJ): $(OBJ_F)%.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

tania: $(TANIA_ENDPOINT_OBJ) $(OBJS)
	$(PREFIX)$(CC) $^ -o $(NAME) $(LINK_FLAGS)

########################################

vania: MOCK_FLAG += -DMOCK_TANIA
vania: all
