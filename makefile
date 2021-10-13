all: test testall

clean:
	rm -v test testall

%: %.c shared.c
	gcc -Ofast -o $@ $<

.PHONY: all clean