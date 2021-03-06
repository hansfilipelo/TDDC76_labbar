#
# Makefile f�r kalkylatorn, niv� G, GNU GCC (g++)
#
# Filkataloger d�r andra delar av programet finns.
EXPRESSION = ../Expression

# Diagnosmeddelanden fr�n kompilatorn (g++) filtreras av gccfilter.
CCC = gccfilter -c -a g++

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -std=c++11 -Wpedantic -Wall -Wextra -Werror

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I$(EXPRESSION)

# L�nkflaggor - Fix f�r att l�sa lokala problem med C++ l�nkbibliotek.
LDFLAGS  += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = kalkylator.o Calculator.o Expression.o Expression_Tree.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
kalkylator: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o kalkylator $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
kalkylator.o: kalkylator.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c kalkylator.cc

Calculator.o: Calculator.h Calculator.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Calculator.cc

Expression.o: $(EXPRESSION)/Expression.h $(EXPRESSION)/Expression.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression.cc

Expression_Tree.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression_Tree.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression_Tree.cc

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar �ven bort det k�rbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# Se upp vid eventuell �ndring, '*' f�r absolut inte finnas f�r sig!!!
#
# '@' medf�r att kommandot inte skrivs ut p� sk�rmen d� det utf�rs av make.
# 'rm' �r ett alias f�r 'rm -i' p� IDA:s system, '\rm' inneb�r att "original-
# versionen", utan flaggan '-i', anv�nds. 
