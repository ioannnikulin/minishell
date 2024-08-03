CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
FTPREFIX = @

LIST_F = lists
LIST_NAMES = ft_list_add_back.c ft_list_add_front.c ft_list_clear.c ft_list_delone.c ft_list_iter.c ft_list_generate.c ft_list_last.c ft_list_new.c ft_list_size.c ft_list_map.c
LIST_SRCS = $(addprefix $(LIST_F)/, $(LIST_NAMES))

DLIST_F = dlists
DLIST_NAMES = ft_dlist_add_back.c ft_dlist_add_front.c ft_dlist_clear.c ft_dlist_delone.c ft_dlist_iter.c ft_dlist_generate.c ft_dlist_generate_int.c ft_dlist_last.c ft_dlist_new.c ft_dlist_size.c ft_dlist_map.c ft_dlist_print.c ft_dlist_ncmp.c
DLIST_SRCS = $(addprefix $(DLIST_F)/, $(DLIST_NAMES))

MEM_F = memory
MEM_NAMES = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_swap.c ft_swap_1.c
MEM_SRCS = $(addprefix $(MEM_F)/, $(MEM_NAMES))

NUM_F = numbers
NUM_NAMES = ft_atoi.c ft_itoa.c ft_xtoa_base.c ft_minmax_int.c ft_minmax_double.c ft_minmax_char.c ft_minmax_uchar.c
NUM_SRCS = $(addprefix $(NUM_F)/, $(NUM_NAMES))

STR_F = strings
STR_NAMES = ft_empty_string.c ft_split.c ft_strlen.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
STR_SRCS = $(addprefix $(STR_F)/, $(STR_NAMES))

SYM_F = symbols
SYM_NAMES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_is_in.c ft_isprint.c ft_isspace.c ft_tolower.c ft_toupper.c
SYM_SRCS = $(addprefix $(SYM_F)/, $(SYM_NAMES))


PRINTF_F = printf
PRINTF_NAMES = aux_printf.c ft_printf.c pad_n_put.c put_c.c put_d.c put_percent.c put_s.c put_u.c put_x.c put_p.c
PRINTF_SRCS = $(addprefix $(PRINTF_F)/, $(PRINTF_NAMES))

GETNEXTLINE_F = get_next_line
GETNEXTLINE_NAMES = get_next_line_bonus.c get_next_line_utils_bonus.c
GETNEXTLINE_SRCS = $(addprefix $(GETNEXTLINE_F)/, $(GETNEXTLINE_NAMES))

SRCS = $(LIST_SRCS) $(DLIST_SRCS) $(MEM_SRCS) $(NUM_SRCS) $(STR_SRCS) $(SYM_SRCS) $(PRINTF_SRCS) $(GETNEXTLINE_SRCS)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I . 
PACK = ar rcs

all: $(NAME)

$(NAME): clean $(OBJS) 
	$(FTPREFIX)$(PACK) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(FTPREFIX)$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -g

clean:
	$(FTPREFIX)rm -f $(OBJS)

fclean: clean
	$(FTPREFIX)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# ------------------------------------------------------------------------------
TESTF = tests
TESTS = $(TESTF)/main_test.c $(TESTF)/ft_isalpha_test.c $(TESTF)/ft_isdigit_test.c $(TESTF)/ft_isalnum_test.c $(TESTF)/ft_isascii_test.c $(TESTF)/ft_isprint_test.c $(TESTF)/ft_strlen_test.c $(TESTF)/ft_memset_test.c $(TESTF)/ft_bzero_test.c $(TESTF)/ft_memcpy_test.c $(TESTF)/ft_memmove_test.c $(TESTF)/ft_strlcpy_test.c $(TESTF)/ft_strlcat_test.c $(TESTF)/ft_tolower_test.c $(TESTF)/ft_toupper_test.c $(TESTF)/ft_strchr_test.c $(TESTF)/ft_strrchr_test.c $(TESTF)/ft_strncmp_test.c $(TESTF)/ft_memchr_test.c $(TESTF)/ft_memcmp_test.c $(TESTF)/ft_strnstr_test.c $(TESTF)/ft_atoi_test.c $(TESTF)/ft_strdup_test.c $(TESTF)/ft_substr_test.c $(TESTF)/ft_strjoin_test.c $(TESTF)/ft_strtrim_test.c $(TESTF)/ft_split_test.c $(TESTF)/ft_itoa_test.c $(TESTF)/ft_striteri_test.c $(TESTF)/ft_strmapi_test.c
NOTMYTESTS = $(TESTF)/ft_putchar_fd_test.c $(TESTF)/ft_putstr_fd_test.c $(TESTS)/ft_putendl_fd_test.c $(TESTF)/ft_putchar_fd_test.c $(TESTF)/ft_putstr_fd_test.c $(TESTF)/ft_putendl_fd_test.c $(TESTF)/ft_putnbr_fd_test.c
JUSTMYTESTS = $(TESTF)/ft_lltoa_base_test.c $(TESTF)/ft_ulltoa_base_test.c $(TESTF)/ft_isspace_test.c $(TESTF)/ft_list_generate_test.c
BONUSTESTS = $(TESTF)/ft_lstnew_test.c $(TESTF)/ft_lstadd_front_test.c $(TESTF)/ft_lstclear_test.c $(TESTF)/ft_lstsize_test.c $(TESTF)/ft_lstlast_test.c $(TESTF)/ft_lstadd_back_test.c $(TESTF)/ft_lstdelone_test.c $(TESTF)/ft_lstmap_test.c $(TESTF)/ft_lstiter_test.c
PRINTFTESTS = $(TESTF)/ft_printf_test.c
GETNEXTLINETESTS = $(TESTF)/get_next_line_test.c
TESTOBJS = $(TESTS:.c=.o) $(JUSTMYTESTS:.c=.o) $(PRINTFTESTS:.c=.o) #$(GETNEXTLINETESTS:.c=.o) #$(BONUSTESTS:.c=.o) 
TESTNAME = $(TESTF)/test
TESTFLAGS = -L. -lft -lbsd
TESTINCLUDES = -I $(TESTF)

SEGFAULTS = $(TESTF)/ft_bzero_segfault_1.c $(TESTF)/ft_memcpy_segfault_1.c $(TESTF)/ft_memcpy_segfault_2.c $(TESTF)/ft_memcpy_segfault_3.c $(TESTF)/ft_memmove_segfault_1.c $(TESTF)/ft_memmove_segfault_2.c $(TESTF)/ft_memmove_segfault_3.c $(TESTF)/ft_strlen_segfault_1.c $(TESTF)/ft_memset_segfault_1.c $(TESTF)/ft_strlcpy_segfault_1.c $(TESTF)/ft_strlcpy_segfault_2.c $(TESTF)/ft_strlcpy_segfault_3.c $(TESTF)/ft_strlcat_segfault_1.c $(TESTF)/ft_strlcat_segfault_2.c $(TESTF)/ft_strlcat_segfault_3.c $(TESTF)/ft_strlcat_segfault_4.c $(TESTF)/ft_strchr_segfault_1.c $(TESTF)/ft_strrchr_segfault_1.c $(TESTF)/ft_strncmp_segfault_1.c $(TESTF)/ft_strncmp_segfault_2.c $(TESTF)/ft_strncmp_segfault_3.c $(TESTF)/ft_memchr_segfault_1.c $(TESTF)/ft_memcmp_segfault_1.c $(TESTF)/ft_memcmp_segfault_2.c $(TESTF)/ft_memcmp_segfault_3.c $(TESTF)/ft_strnstr_segfault_1.c $(TESTF)/ft_strdup_segfault_1.c $(TESTF)/ft_substr_segfault_1.c $(TESTF)/ft_substr_segfault_2.c $(TESTF)/ft_strjoin_segfault_1.c $(TESTF)/ft_strjoin_segfault_2.c $(TESTF)/ft_strjoin_segfault_3.c $(TESTF)/ft_strtrim_segfault_1.c $(TESTF)/ft_strtrim_segfault_2.c $(TESTF)/ft_strtrim_segfault_3.c
AUX = $(TESTF)/aux.c
AUXOBJ = $(AUX:.c=.o)
SEGFAULTOBJS = $(SEGFAULTS:.c=.o)
SEGFAULTNAMES = $(SEGFAULTS:.c=.sf)

$(TESTOBJS): %.o: %.c
	$(FTPREFIX)$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

$(SEGFAULTOBJS): %.o: %.c
	$(FTPREFIX)$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

$(AUXOBJ): %.o: %.c
	$(FTPREFIX)$(CC) -Werror -c $< -o $@ $(TESTINCLUDES) -g

testfclean:
	$(FTPREFIX)rm -f $(TESTOBJS)
	$(FTPREFIX)rm -f $(SEGFAULTOBJS)
	$(FTPREFIX)rm -f $(TESTNAME)
	$(FTPREFIX)rm -f $(SEGFAULTNAMES)

goodtests: $(TESTOBJS) $(AUXOBJ)
	$(FTPREFIX)$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $(TESTNAME) -g

$(SEGFAULTNAMES): %.sf: %.o $(AUXOBJ)
	$(FTPREFIX)$(CC) $^ $(TESTFLAGS) $(TESTINCLUDES) -o $@ -g

test: $(SEGFAULTNAMES) goodtests

retest: testfclean test

go: re retest
	$(FTPREFIX)tests/test
	$(FTPREFIX)rm -rf tmp.tst
	$(FTPREFIX)valgrind --leak-check=full --show-leak-kinds=all tests/test
	# -------- Multiple segfaults expected, which is part of the testing. --------
	# -------- Stay calm unless you see an error message in UPPER CASE. --------
	$(FTPREFIX)$(SEGFAULTNAMES:%.sf=%.sf ||) true
	# -------- Testing finished. --------
