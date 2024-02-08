#206398596 Guy Reuveni
#208189126 Niv Swisa

CC = gcc
CFLAGS = -std=c11 -O2 -march=native -mavx512f -mavx512bw -I.

LDFLAGS = -lm

TARGET = part1.out

SRCS = main.c b64.c hamming_dist.s

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
