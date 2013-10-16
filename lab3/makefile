	CCC = /usr/local/bin/g++
	CCFLAGS = -g -std=c++11 -Wall -Wextra -Werror
	LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++
	OBJECTS = kalkylator.o Expression_Tree.o Expression.o

kalkylator: $(OBJECTS)
	$(CCC) $(CCFLAGS) $(OBJECTS) -o kalkylator

kalkylator.o: kalkylator.cc
	$(CCC) $(CCFLAGS) -c kalkylator.cc

Expression.o: Expression/Expression.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression.cc

Expression_Tree.o: Expression/Expression_Tree.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression_Tree.cc

clean:
	@ \rm -f *.o

