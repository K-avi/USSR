
# Makefile template for a shared library in C
# https://www.topbug.net/blog/2019/10/28/makefile-template-for-a-shared-library-in-c-with-explanations/

CC = gcc  

CFLAGS := -O1 -std=gnu17 -Wall -Wextra -Wpedantic -Wno-unused-parameter -fPIC
LDFLAGS := -shared   # linking flags
DEBUG_FLAGS := -g -fsanitize=address -fsanitize=object-size -fno-optimize-sibling-calls -fsanitize=undefined -fsanitize=leak -fsanitize=alignment


TARGET_LIB := ../ussr_lib.so  # target lib
DBG_LIB := ../ussr_dbg.so
TEST := ../test
TEST_DBG := ../test_dbg 

SRCS := ussr_common.c ussr_convert.c ussr_misc.c ussr_basic.c ussr_cat.c ussr_print.c ussr_dup.c ussr_redef.c ussr_strtab.c ussr_split.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(TEST_DBG): $(SRCS) main_test.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $(TEST_DBG) 

$(TEST): $(SRCS) main_test.c
	$(CC) $(CFLAGS)  $^ -o $(TEST) 


.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)