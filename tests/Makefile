# Force double precision with floating point operations
LFLAGS = -msse2 -mfpmath=sse

CHECK_LIBS = `pkg-config --cflags --libs check`
CFLAGS += -I../ -fprofile-arcs -ftest-coverage
LDFLAGS += -fprofile-arcs -ftest-coverage $(CHECK_LIBS)
TARGET = check

.PHONY: all

all: $(TARGET) run gcov

check: check_cayenne_lpp.o cayenne_lpp.o
	gcc *.o $(LDFLAGS) -o $(TARGET)

check_cayenne_lpp.o: check_cayenne_lpp.c
	gcc $(CFLAGS) -c $< -o $@

cayenne_lpp.o: ../cayenne_lpp.c
	gcc $(LFLAGS) $(CFLAGS) -c $< -o $@

run:
	$(CURDIR)/check

gcov:
	gcov ../cayenne_lpp.c --object-directory=$(CURDIR)

clean:
	rm -f *.o *.gc* *.html $(TARGET)
