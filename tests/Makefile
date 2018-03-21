CFLAGS += -I../

.PHONY: all

all: test

test: main.o cayenne-lpp.o
	gcc -o test main.o cayenne-lpp.o

main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

cayenne-lpp.o: ../cayenne-lpp.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm *.o test
