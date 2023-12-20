CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2

SRCS = examples/wikibot.c
OBJS = $(SRCS:.c=.o)


BOT = wikibot 

$(BOT): $(OBJS)
	$(CC) $(OBJS) -o $(BOT)

run: $(BOT)
	./$(BOT)


clean:
	rm -f $(OBJS)	$(BOT)

.PHONY: clean
