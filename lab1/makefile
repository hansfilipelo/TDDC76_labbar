	CCC = clang++
	CCFLAGS = -g -std=c++11 -Wpedantic -Wall -Wextra -Werror
	LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

lab1-5: lab1-5.o list.o
	$(CCC) $(CCFLAGS) lab1-5.o list.o -o lab1-5

lab1-5.o: lab1-5.cc
	$(CCC) $(CCFLAGS) -c lab1-5.cc 

list.o: list.cc
	$(CCC) $(CCFLAGS) -c list.cc

clean:
	@ \rm -f *.o
