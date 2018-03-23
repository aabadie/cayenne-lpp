.PHONY: all test test-clean doc doc-clean

all: test

test:
	CFLAGS=$(CFLAGS) make -C tests

test-clean:
	make -C tests clean

doc:
	make -C doc

doc-clean:
	make -C doc clean