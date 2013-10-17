	CCC = /usr/local/bin/g++
	CCFLAGS = -g -std=c++11 -Wall -Wextra -Werror
	LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++
	OBJECTS = expression-test.o Expression_Tree.o Expression.o

expression-test: $(OBJECTS)
	$(CCC) $(CCFLAGS) $(OBJECTS) -o expression-test

expression-test.o: Expression/expression-test.cc
	$(CCC) $(CCFLAGS) -c Expression/expression-test.cc

Expression.o: Expression/Expression.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression.cc

Expression_Tree.o: Expression/Expression_Tree.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression_Tree.cc

clean:
	@ \rm -f *.o

