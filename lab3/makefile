	CCC = g++
	CCFLAGS = -g -std=c++11 -Wall -Wextra -Werror
	LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++
	OBJECTS = kalkylator.o Expression_Tree.o Expression.o Variable_Table.o Calculator.o

kalkylator: $(OBJECTS)
	$(CCC) $(CCFLAGS) -o kalkylator $(OBJECTS)

kalkylator.o: Calculator/kalkylator.cc
	$(CCC) $(CCFLAGS) -c Calculator/kalkylator.cc

Expression.o: Expression/Expression.h Expression/Expression.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression.cc

Expression_Tree.o: Expression/Expression_Tree.h Expression/Expression_Tree.cc
	$(CCC) $(CCFLAGS) -c Expression/Expression_Tree.cc

Variable_Table.o: Variable_Table/Variable_Table.h Variable_Table/Variable_Table.cc
	$(CCC) $(CCFLAGS) -c Variable_Table/Variable_Table.cc
    
Calculator.o: Calculator/Calculator.h Calculator/Calculator.cc
	$(CCC) $(CCFLAGS) -c Calculator/Calculator.cc

clean:
	@ \rm -f *.o

