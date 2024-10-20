CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = -lft -Llibft -lreadline
PREFIX =
MOCK_FLAG =

SOURCE_F = sources
TEST_F = tests

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_0.c mock_1.c mock_2.c mock_3.c mock_4.c mock_5.c mock_6.c mock_7.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

COMMANDS_NAMES = option_cd.c option_echo.c option_env.c option_exit.c option_export.c option_external.c option_pwd.c option_unset.c get_envvars_for_execve.c
COMMANDS_F = commands
COMMANDS_SRCS = $(addprefix $(COMMANDS_F)/,$(COMMANDS_NAMES))

SRC_NAMES = finalize.c param_init.c param_get_envvars.c wrappers.c input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS) exec_text_tree.c exec_text_tree_node.c $(COMMANDS_SRCS)
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

TEST_NAMES = main_test.c input_to_text_tree_test.c
TEST_SRCS = $(addprefix $(TEST_F)/, $(TEST_NAMES))
TEST_FNAME = $(TEST_F)/test

OBJ_F = build/
TEST_OBJ_F = build/tests/
OBJS = $(addprefix $(OBJ_F), $(SRC_NAMES:.c=.o))
TEST_OBJS = $(addprefix $(TEST_OBJ_F), $(TEST_NAMES:.c=.o))
ENDPOINT_OBJ = $(OBJ_F)$(ENDPOINT_NAME:.c=.o)
INCLUDES = -I . -I libft

DIRS = $(COMMANDS_F) $(INPUT_TO_TEXT_TREE_MOCK_F) tests

OBJ_DIRS = $(addprefix $(OBJ_F), $(DIRS)) $(TEST_OBJ_F)

vpath %.c $(SOURCE_F) $(SOURCE_F)/$(COMMANDS_F) $(SOURCE_F)/$(INPUT_TO_TEXT_TREE_MOCK_F)

all: $(OBJ_DIRS) pre $(NAME)

$(OBJ_DIRS):
	$(PREFIX)mkdir -p $(OBJ_DIRS)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $^ -o $@ $(LINK_FLAGS)

$(OBJ_F)%.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(TEST_OBJ_F)%.o: $(TEST_F)/%.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

preclean:
	$(PREFIX)cd libft && make clean

prefclean:
	$(PREFIX)cd libft && make fclean

prere:
	$(PREFIX)cd libft && make re

clean:
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJ) $(TANIA_ENDPOINT_OBJ) $(VANIA_ENDPOINT_OBJ)
	@if [ -d $(OBJ_F) ]; then $(PREFIX)rm -rf $(OBJ_F); fi

fclean: clean
	$(PREFIX)rm -f $(NAME)
	$(PREFIX)rm -f $(ENDPOINT_OBJ)
	$(PREFIX)rm -f $(ENDPOINT_OBJ)
	@if [ "$(wildcard build)" ]; then $(PREFIX)rm -r build; fi

re: fclean all

test: $(OBJ_DIRS) $(OBJS) $(TEST_OBJS)
	$(PREFIX)$(CC) $(OBJS) $(TEST_OBJS) -o $(TEST_FNAME) $(LINK_FLAGS)

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

TANIA_ENDPOINT = sources/tanya_main.c
TANIA_ENDPOINT_OBJ = $(OBJ_F)$(TANIA_ENDPOINT:.c=.o)

$(TANIA_ENDPOINT_OBJ): $(OBJ_F)%.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

tania: $(TANIA_ENDPOINT_OBJ) $(OBJS)
	$(PREFIX)$(CC) $^ -o $(NAME) $(LINK_FLAGS)

########################################

vania: MOCK_FLAG += -DMOCK_TANIA
vania: all