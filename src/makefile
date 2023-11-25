
# Makefile template for a shared library in C
# https://www.topbug.net/blog/2019/10/28/makefile-template-for-a-shared-library-in-c-with-explanations/

CC = gcc  

CFLAGS := -O1 -std=gnu17 -Wall -Wextra -Wpedantic -Wno-unused-parameter -fPIC
LDFLAGS := -shared   # linking flags
DEBUG_FLAGS := -g -fsanitize=address -fsanitize=object-size -fno-optimize-sibling-calls -fsanitize=undefined -fsanitize=leak -fsanitize=alignment


TARGET_LIB := ../ussr_lib.so  # target lib
DBG_LIB := ../ussr_dbg.so
TEST := ../test

SRCS := ussr_common.c ussr_convert.c ussr_misc.c ussr_string.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(TEST): $(SRCS) main_test.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $(TEST) 

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)