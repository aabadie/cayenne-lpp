CFLAGS += -I../

# Force double precision with floating point operations
LFLAGS = -msse2 -mfpmath=sse
CHECK_LIBS = `pkg-config --cflags --libs check`

.PHONY: all

all: check

check: check_cayenne_lpp.o cayenne_lpp.o
	gcc -o check check_cayenne_lpp.o cayenne_lpp.o $(CHECK_LIBS)

check_cayenne_lpp.o: check_cayenne_lpp.c
	gcc $(CFLAGS) -c $< -o $@

cayenne_lpp.o: ../cayenne_lpp.c
	gcc $(LFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o check
