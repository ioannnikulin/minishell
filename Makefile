# CC = cc
# NAME = minishell
# COMPILE_FLAGS = -Wall -Wextra -Werror
# LINK_LIBFT_FLAGS = -lft -Llibft
# PREFIX =

# SOURCES_F = sources

# SRC_NAMES = finalize.c init_param.c utils.c wrappers.c
# ENDPOINT_NAME = main.c

# SRC_SRCS = $(addprefix $(SOURCES_F)/, $(SRC_NAMES))
# ENDPOINT_SRC = $(addprefix $(SOURCES_F)/, $(ENDPOINT_NAME))

# OBJS = $(SRC_SRCS:.c=.o)
# ENDPOINT_OBJ = $(ENDPOINT_SRC:.c=.o)
# INCLUDES = -I . -I libft

# all: $(NAME)

# pre:
# 	$(PREFIX)cd libft && make all

# $(NAME): $(OBJS) $(ENDPOINT_OBJ)
# 	$(PREFIX)$(CC) $^ -o $@ $(LINK_LIBFT_FLAGS)

# $(OBJS): %.o: %.c
# 	$(PREFIX)$(CC) $(COMPILE_FLAGS) $< -o $@ -g $(INCLUDES) -c

# preclean:
# 	$(PREFIX)cd libft && make clean

# prefclean:
# 	$(PREFIX)cd libft && make fclean

# clean:
# 	$(PREFIX)rm -f $(OBJS)

# fclean:
# 	$(PREFIX)rm -f $(NAME)

# re: fclean all

# fulltest:
# 	$(PREFIX)cd libft && make fulltest

# PHONY: all pre clean fclean re
# ########################################

# TANIA_ENDPOINT = sources/create_environ_list.c
# TANIA_ENDPOINT_OBJ = $(TANIA_ENDPOINT:.c=.o)

# tania: $(TANIA_ENDPOINT_OBJ) $(OBJS)

# Compiler settings

CC = cc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
LDFLAGS = -Llibft
LIBS = -lft

# Paths and files
SOURCES_F = sources
SRC_NAMES = finalize.c init_param.c utils.c wrappers.c
ENDPOINT_NAME = main.c
SRC_SRCS = $(addprefix $(SOURCES_F)/, $(SRC_NAMES))
ENDPOINT_SRC = $(addprefix $(SOURCES_F)/, $(ENDPOINT_NAME))
OBJS = $(SRC_SRCS:.c=.o)
ENDPOINT_OBJ = $(ENDPOINT_SRC:.c=.o)
INCLUDES = -I . -I libft

# All target to compile the program
all: pre $(NAME)

# Pre-compilation step for libft
pre:
	$(PREFIX)$(MAKE) -C libft

# Linking the final binary
$(NAME): $(OBJS) $(ENDPOINT_OBJ)
	$(CC) $(OBJS) $(ENDPOINT_OBJ) -o $@ $(LDFLAGS) $(LIBS)

# Rule for compiling object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean libft and project object files
preclean:
	$(PREFIX)$(MAKE) -C libft clean

# Clean everything, including binary
prefclean: clean
	$(PREFIX)$(MAKE) -C libft fclean

clean:
	$(PREFIX)rm -f $(OBJS) $(ENDPOINT_OBJ)

fclean: clean
	$(PREFIX)rm -f $(NAME)

# Rebuild everything
re: fclean all

# Run tests in libft
fulltest:
	$(PREFIX)$(MAKE) -C libft fulltest

# Phony targets
.PHONY: all pre clean fclean re
