CFLAGS += -I../

# Force double precision with floating point operations
LFLAGS = -msse2 -mfpmath=sse

.PHONY: all

all: example

example: main.o cayenne_lpp.o
	gcc -o example main.o cayenne_lpp.o

main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

cayenne_lpp.o: ../cayenne_lpp.c
	gcc $(LFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o example
