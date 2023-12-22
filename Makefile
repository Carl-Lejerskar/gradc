CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 

# Include all source files required for the project
SRCS = src/core/graph.c src/core/loss.c src/core/optimizer.c src/core/tensor.c src/core/tensor_ops.c \
       src/layers/activation.c src/layers/convolution.c src/layers/dense.c src/layers/pooling.c \
       src/utils/utils.c
OBJS = $(SRCS:.c=.o)
TEST_SRCS = $(wildcard tests/*.c)
TEST_EXECS = $(TEST_SRCS:.c=)

INCLUDES = -I include/core -I include/layers -I include/utils

BOT = wikibot

$(BOT): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(BOT)

print: 
	@echo "Object files: $(OBJS)"
	@echo "Includes: $(INCLUDES)"

run: $(BOT)
	./$(BOT)

clean:
	rm -f $(OBJS) $(BOT) $(TEST_EXECS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_EXECS): %: %.c $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< $(OBJS)

test: $(TEST_EXECS)
	@echo "Test sources: $(TEST_SRCS)"
	@echo "Test execs: $(TEST_EXECS)"
	@for exec in $(TEST_EXECS); do \
		./$$exec;                    \
	done
	$(MAKE) clean

.PHONY: clean test run

