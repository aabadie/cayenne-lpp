.PHONY: all example example-clean doc doc-clean check check-clean

all: example

example:
	CFLAGS=$(CFLAGS) make -C example

example-clean:
	make -C example clean

doc:
	make -C doc

doc-clean:
	make -C doc clean

check:
	make -C tests

check-clean:
	make -C tests clean
