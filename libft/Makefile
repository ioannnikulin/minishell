CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g
FTPREFIX = @

SOURCES_F = sources

LIST_F = lists
LIST_NAMES = ft_list_add_back.c ft_list_add_front.c ft_list_clear.c ft_list_delone.c ft_list_iter.c ft_list_generate.c ft_list_last.c ft_list_new.c ft_list_size.c ft_list_map.c
LIST_SRCS = $(addprefix $(SOURCES_F)/$(LIST_F)/, $(LIST_NAMES))

DLIST_F = dlists
DLIST_NAMES = ft_dlist_add_back.c ft_dlist_add_front.c ft_dlist_clear.c ft_dlist_delone.c ft_dlist_iter.c ft_dlist_generate.c ft_dlist_generate_int.c ft_dlist_last.c ft_dlist_new.c ft_dlist_size.c ft_dlist_map.c ft_dlist_print.c ft_dlist_ncmp.c
DLIST_SRCS = $(addprefix $(SOURCES_F)/$(DLIST_F)/, $(DLIST_NAMES))

MAPSS_F = map/mapss
MAPSS_NAMES = ft_mapss_print.c ft_mapss_add.c ft_mapss_insert.c ft_mapss_finalize.c ft_mapss_ncmp.c ft_mapss_get.c ft_mapss_del.c ft_mapss_gen.c
MAPSS_SRCS = $(addprefix $(SOURCES_F)/$(MAPSS_F)/, $(MAPSS_NAMES))

TREE_F = tree
TREE_NAMES = ft_tree_print.c ft_treenode_free.c ft_treenode_insert.c ft_tree_make.c ft_tree_apply.c ft_tree_print_wrappers.c ft_treenode_insert_wrappers.c ft_tree_cmp.c
TREE_SRCS = $(addprefix $(SOURCES_F)/$(TREE_F)/, $(TREE_NAMES))

MEM_F = memory
MEM_NAMES = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_swap.c ft_swap_1.c ft_assign.c ft_cmp.c ft_new.c ft_free.c ft_free_s.c ft_free_null.c ft_tuples.c
MEM_SRCS = $(addprefix $(SOURCES_F)/$(MEM_F)/, $(MEM_NAMES))

NUM_F = numbers
NUM_NAMES = ft_atoi.c ft_itoa.c ft_xtoa_base.c ft_minmax_int.c ft_minmax_double.c ft_minmax_char.c ft_minmax_uchar.c
NUM_SRCS = $(addprefix $(SOURCES_F)/$(NUM_F)/, $(NUM_NAMES))

STR_F = strings
STR_NAMES = ft_empty_string.c ft_split.c ft_split_str.c ft_split_str_utils.c ft_split_skip_delim.c ft_split_skip_delim_utils.c ft_strlen.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_putstr_fd.c ft_free_delims.c
STR_SRCS = $(addprefix $(SOURCES_F)/$(STR_F)/, $(STR_NAMES))

SYM_F = symbols
SYM_NAMES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_is_in.c ft_isprint.c ft_isspace.c ft_tolower.c ft_toupper.c
SYM_SRCS = $(addprefix $(SOURCES_F)/$(SYM_F)/, $(SYM_NAMES))

PRINTF_F = printf
PRINTF_NAMES = aux_printf.c ft_printf.c pad_n_put.c put_c.c put_d.c put_percent.c put_s.c put_u.c put_x.c put_p.c
PRINTF_SRCS = $(addprefix $(SOURCES_F)/$(PRINTF_F)/, $(PRINTF_NAMES))

GNL_F = get_next_line
GNL_NAMES = get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_SRCS = $(addprefix $(SOURCES_F)/$(GNL_F)/, $(GNL_NAMES))

FLOW_F = control_flow
FLOW_NAMES = ft_if.c
FLOW_SRCS = $(addprefix $(SOURCES_F)/$(FLOW_F)/, $(FLOW_NAMES))

SRCS = $(LIST_SRCS) $(DLIST_SRCS) $(MAPSS_SRCS) $(TREE_SRCS) $(MEM_SRCS) $(NUM_SRCS) $(STR_SRCS) $(SYM_SRCS)  $(PRINTF_SRCS) $(GNL_SRCS) $(FLOW_SRCS)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I .
PACK = ar rcs

all: $(NAME)

$(NAME): clean $(OBJS)
	$(FTPREFIX)$(PACK) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(FTPREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(FTPREFIX)rm -f $(OBJS)

fclean: clean
	$(FTPREFIX)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# ------------------------------------------------------------------------------
TESTF = tests

LIST_TEST_NAMES = $(LIST_NAMES)
LIST_TEST_SRCS = $(addprefix $(TESTF)/$(LIST_F)/, $(subst .c,_test.c,$(LIST_TEST_NAMES)) lists_test.c)

DLIST_TEST_NAMES = $(DLIST_NAMES)
DLIST_TEST_SRCS = $(addprefix $(TESTF)/$(DLIST_F)/, $(subst .c,_test.c,$(DLIST_TEST_NAMES)) dlists_test.c)

MAPSS_TEST_NAMES = mapss_test.c ft_mapss_add_test.c ft_mapss_print_test.c ft_mapss_gen_test.c
MAPSS_TEST_SRCS = $(addprefix $(TESTF)/$(MAPSS_F)/, $(MAPSS_TEST_NAMES))

TREE_TEST_NAMES = tree_test.c ft_tree_print_test.c ft_treenode_insert_child_before_first_test.c ft_treenode_insert_child_idx_test.c
TREE_TEST_SRCS = $(addprefix $(TESTF)/$(TREE_F)/, $(TREE_TEST_NAMES))

MEM_TEST_NAMES = ft_bzero_test.c ft_memchr_test.c ft_memcmp_test.c ft_memcpy_test.c ft_memmove_test.c ft_memset_test.c memory_test.c
MEM_TEST_SRCS = $(addprefix $(TESTF)/$(MEM_F)/, $(MEM_TEST_NAMES))

NUM_TEST_NAMES = ft_atoi_test.c ft_itoa_test.c ft_lltoa_base_test.c ft_ulltoa_base_test.c numbers_test.c
NUM_TEST_SRCS = $(addprefix $(TESTF)/$(NUM_F)/, $(NUM_TEST_NAMES))

STR_TEST_NAMES = ft_split.c ft_split_str.c ft_split_skip_delim.c ft_strlen.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STR_TEST_SRCS = $(addprefix $(TESTF)/$(STR_F)/, $(subst .c,_test.c,$(STR_TEST_NAMES)) strings_test.c)

SYM_TEST_NAMES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_tolower.c ft_toupper.c
SYM_TEST_SRCS = $(addprefix $(TESTF)/$(SYM_F)/, $(subst .c,_test.c,$(SYM_TEST_NAMES)) symbols_test.c)

PRINTF_TEST_SRCS = $(TESTF)/$(PRINTF_F)/ft_printf_test.c

GNL_TEST_NAMES = get_next_line_test.c
GNL_TEST_SRCS = $(addprefix $(TESTF)/$(GNL_F)/, $(GNL_TEST_NAMES))
MAIN_TEST = $(TESTF)/main_test.c

TESTOBJS = $(MAIN_TEST:.c=.o) $(LIST_TEST_SRCS:.c=.o) $(MAPSS_TEST_SRCS:.c=.o) $(TREE_TEST_SRCS:.c=.o) $(MEM_TEST_SRCS:.c=.o) $(STR_TEST_SRCS:.c=.o) $(SYM_TEST_SRCS:.c=.o) $(NUM_TEST_SRCS:.c=.o) $(PRINTF_TEST_SRCS:.c=.o) $(GNL_TEST_SRCS:.c=.o) #$(DLIST_TEST_SRCS:.c=.o)
TESTNAME = $(TESTF)/test
TESTFLAGS = -L. -lft -lbsd
TESTINCLUDES = -I $(TESTF)

#SEGFAULTS = $(TESTF)/ft_bzero_segfault_1.c $(TESTF)/ft_memcpy_segfault_1.c $(TESTF)/ft_memcpy_segfault_2.c $(TESTF)/ft_memcpy_segfault_3.c $(TESTF)/ft_memmove_segfault_1.c $(TESTF)/ft_memmove_segfault_2.c $(TESTF)/ft_memmove_segfault_3.c $(TESTF)/ft_strlen_segfault_1.c $(TESTF)/ft_memset_segfault_1.c $(TESTF)/ft_strlcpy_segfault_1.c $(TESTF)/ft_strlcpy_segfault_2.c $(TESTF)/ft_strlcpy_segfault_3.c $(TESTF)/ft_strlcat_segfault_1.c $(TESTF)/ft_strlcat_segfault_2.c $(TESTF)/ft_strlcat_segfault_3.c $(TESTF)/ft_strlcat_segfault_4.c $(TESTF)/ft_strchr_segfault_1.c $(TESTF)/ft_strrchr_segfault_1.c $(TESTF)/ft_strncmp_segfault_1.c $(TESTF)/ft_strncmp_segfault_2.c $(TESTF)/ft_strncmp_segfault_3.c $(TESTF)/ft_memchr_segfault_1.c $(TESTF)/ft_memcmp_segfault_1.c $(TESTF)/ft_memcmp_segfault_2.c $(TESTF)/ft_memcmp_segfault_3.c $(TESTF)/ft_strnstr_segfault_1.c $(TESTF)/ft_strdup_segfault_1.c $(TESTF)/ft_substr_segfault_1.c $(TESTF)/ft_substr_segfault_2.c $(TESTF)/ft_strjoin_segfault_1.c $(TESTF)/ft_strjoin_segfault_2.c $(TESTF)/ft_strjoin_segfault_3.c $(TESTF)/ft_strtrim_segfault_1.c $(TESTF)/ft_strtrim_segfault_2.c $(TESTF)/ft_strtrim_segfault_3.c
AUX = $(TESTF)/aux.c
AUXOBJ = $(AUX:.c=.o)
SEGFAULTOBJS = $(SEGFAULTS:.c=.o)
#SEGFAULTNAMES = $(SEGFAULTS:.c=.sf)

$(TESTOBJS): %.o: %.c
	$(FTPREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(TESTINCLUDES)

#$(SEGFAULTOBJS): %.o: %.c
#	$(FTPREFIX)$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

$(AUXOBJ): %.o: %.c
	$(FTPREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(TESTINCLUDES)

testfclean:
	$(FTPREFIX)rm -f $(TESTOBJS)
	$(FTPREFIX)rm -f $(SEGFAULTOBJS)
	$(FTPREFIX)rm -f $(TESTNAME)
#	$(FTPREFIX)rm -f $(SEGFAULTNAMES)

goodtests: $(TESTOBJS) $(AUXOBJ)
	$(FTPREFIX)$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $(TESTNAME)

#(SEGFAULTNAMES): %.sf: %.o $(AUXOBJ)
#	$(FTPREFIX)$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $@ -g

test: goodtests #$(SEGFAULTNAMES)

retest: testfclean test

fulltest: re retest
	$(FTPREFIX)norminette libft.h sources/*
	$(FTPREFIX)tests/test
	$(FTPREFIX)rm -rf tmp.tst
	$(FTPREFIX)valgrind --leak-check=full --show-leak-kinds=all tests/test "memcheck"
	@# -------- Multiple segfaults expected, which is part of the testing. --------
	@# -------- Stay calm unless you see an error message in UPPER CASE. --------
#	$(FTPREFIX)$(SEGFAULTNAMES:%.sf=%.sf ||) true
	# -------- Testing finished. --------
