	CCC = clang++
	CCFLAGS = -g -std=c++11 -Wall -Wextra -Werror
	LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

kalkylator: kalkylator.o Expression_Tree.o
	$(CCC) $(CCFLAGS) kalkylator.o Expression_Tree.o -o kalkylator

kalkylator.o: kalkylator.cc
	$(CCC) $(CCFLAGS) -c kalkylator.cc

Expression_Tree.o: Expression/Expression_Tree.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression_Tree.cc

clean:
	@ \rm -f *.o
