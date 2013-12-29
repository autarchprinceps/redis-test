test: test.c
	gcc -lhiredis -o test test.c

run: test
	./test 127.0.0.1 6379
