cc = gcc
cflags = -Wall -std=c11

common_srcs = $(wildcard common/*.c)

%: %.c
	$(cc) $(cflags) $(common_srcs) $< -o exe

clean:
	rm ./exe
