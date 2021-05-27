test: test.o
	./test.o
	#debug50 test.o
	rm test.o

test.o: test.cpp Animal.cpp
	g++ -std=c++11 test.cpp Animal.cpp -o test.o #-ggdb

