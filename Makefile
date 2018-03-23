.PHONY: all test doc

all: test

test:
	make -C tests

doc:
	make -C doc

doc-clean:
	make -C doc clean