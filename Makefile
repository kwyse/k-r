cc = gcc
cflags = -Wall -pedantic -std=c11

%: %.c
	@$(cc) $(cflags) $< -o $@
	@./$@
	@rm $@
