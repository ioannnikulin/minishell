CC = cc
NAME = minishell
COMPILE_FLAGS = -Wall -Wextra -Werror
LINK_LIBFT_FLAGS = -lft -Llibft
PREFIX =

SOURCE_F = sources
TEST_F = tests

INPUT_TO_TEXT_TREE_MOCK_NAMES = input_to_text_tree_mock.c mock_1.c mock_2.c mock_3.c mock_4.c mock_5.c mock_6.c
INPUT_TO_TEXT_TREE_MOCK_F = input_to_text_tree_mocks
INPUT_TO_TEXT_TREE_MOCK_SRCS = $(addprefix $(INPUT_TO_TEXT_TREE_MOCK_F)/, $(INPUT_TO_TEXT_TREE_MOCK_NAMES))

SRC_NAMES = finalize.c init_param.c utils.c wrappers.c input_to_text_tree.c $(INPUT_TO_TEXT_TREE_MOCK_SRCS)
ENDPOINT_NAME = main.c

SRC_SRCS = $(addprefix $(SOURCE_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCE_F)/, $(ENDPOINT_NAME))

OBJS = $(SRC_SRCS:.c=.o)
ENDPOINT_OBJ = $(ENDPOINT_SRC:.c=.o)
INCLUDES = -I . -I libft

TEST_NAMES = main_test.c input_to_text_tree_test.c ft_split_buf_test.c
TEST_SRCS = $(addprefix $(TEST_F)/, $(TEST_NAMES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: pre $(NAME)

pre:
	$(PREFIX)cd libft && make all

$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(PREFIX)$(CC) $^ -o $@ $(LINK_LIBFT_FLAGS)

$(OBJS): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ -g $(INCLUDES) -c

$(TEST_OBJS): %.o: %.c
	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ -g $(INCLUDES) -c

preclean:
	$(PREFIX)cd libft && make clean

prefclean:
	$(PREFIX)cd libft && make fclean

clean:
	$(PREFIX)rm -f $(OBJS) $(TEST_OBJS)

fclean:
	$(PREFIX)rm -f $(NAME) $(TEST_OBJS)
	$(PREFIX)rm -f $(OBJS)

re: fclean all

test: $(OBJS) $(TEST_OBJS)
	$(PREFIX)$(CC) $^ -o $@ $(LINK_LIBFT_FLAGS)

fulltest:
	$(PREFIX)cd libft && make fulltest
	$(PREFIX)make test

PHONY: all pre clean fclean re test fulltest
########################################

TANIA_ENDPOINT = sources/create_environ_list.c
TANIA_ENDPOINT_OBJ = $(TANIA_ENDPOINT:.c=.o)

tania: $(TANIA_ENDPOINT_OBJ) $(OBJS)
