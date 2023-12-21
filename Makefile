CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 

# Include all source files required for the project
SRCS = src/core/graph.c src/core/loss.c src/core/optimizer.c src/core/tensor.c \
       src/layers/activation.c src/layers/convolution.c src/layers/dense.c src/layers/pooling.c \
       src/utils/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include/core -I include/layers -I include/utils

BOT = wikibot

$(BOT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BOT)

run: $(BOT)
	./$(BOT)

clean:
	rm -f $(OBJS) $(BOT) test_runner

test:
	$(CC) $(CFLAGS) -g $(INCLUDES) -o tensor_tests tests/tensor_tests.c $(SRCS)
	./tensor_tests

.PHONY: clean test run

