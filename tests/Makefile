CFLAGS += -I../

.PHONY: all

all: test

test: main.o cayenne_lpp.o
	gcc -o test main.o cayenne_lpp.o

main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

cayenne_lpp.o: ../cayenne_lpp.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm *.o test
