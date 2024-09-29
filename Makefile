CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c
LINK_FLAGS = -lft -Llibft -lreadline
PREFIX =
MOCK_FLAG =

SOURCE_F = sources
TEST_F = tests

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_0.c mock_1.c mock_2.c mock_3.c mock_4.c mock_5.c mock_6.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

SRC_NAMES = finalize.c init_param.c utils.c wrappers.c input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS) exec_text_tree.c
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

OBJS = $(SRC_SRCS:.c=.o)
ENDPOINT_OBJ = $(ENDPOINT_SRC:.c=.o)
INCLUDES = -I . -I libft

TEST_NAMES = main_test.c input_to_text_tree_test.c
TEST_SRCS = $(addprefix $(TEST_F)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_FNAME = $(TEST_F)/test

all: $(NAME)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $^ -o $@ $(LINK_FLAGS)

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(ENDPOINT_OBJ): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(MOCK_FLAG)

$(TEST_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

preclean:
	$(PREFIX)cd libft && make clean

prefclean:
	$(PREFIX)cd libft && make fclean

prere:
	$(PREFIX)cd libft && make re

clean:
	$(PREFIX)rm -f $(OBJS) $(VANIA_ENDPOINT_OBJ) $(TANIA_ENDPOINT_OBJ)

fclean: clean
	$(PREFIX)rm -f $(NAME)

re: fclean all

test: $(OBJS) $(TEST_OBJS)
	$(PREFIX)$(CC) $^ -o $(TEST_FNAME) $(LINK_FLAGS)

testclean:
	$(PREFIX)rm -f $(TEST_OBJS)

testfclean: testclean
	$(PREFIX)rm -f $(TEST_FNAME)

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
TANIA_ENDPOINT_OBJ = $(TANIA_ENDPOINT:.c=.o)

$(TANIA_ENDPOINT_OBJ): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES)

tania: $(TANIA_ENDPOINT_OBJ) $(OBJS)
	$(PREFIX)$(CC) $^ -o $(NAME) $(LINK_FLAGS)

########################################

vania: MOCK_FLAG += -DMOCK_TANIA
vania: all
