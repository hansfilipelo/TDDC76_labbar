#
# Makefile f�r kalkylatorn, Niv� G. GNU GCC (g++)
#
# Filkatalog d�r andra delar av programet finns.
EXPRESSION = ../Expression

# Kompilator
CCC = g++

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS  += -std=c++98 -pedantic -Wall -Wextra

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I$(EXPRESSION)

# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = kalkylator.o Calculator.o Expression.o Expression_Tree.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
kalkylator: $(OBJECTS) Makefile
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -o kalkylator $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning)
kalkylator.o: Calculator.h kalkylator.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c kalkylator.cc

Calculator.o: $(EXPRESSION)/Expression.h Calculator.h Calculator.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c Calculator.cc

Expression.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression.h $(EXPRESSION)/Expression.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c $(EXPRESSION)/Expression.cc

Expression_Tree.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression_Tree.cc
	$(CCC) $(CCFLAGS) $(CPPFLAGS) -c $(EXPRESSION)/Expression_Tree.cc

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core

# 'make zap' tar �ven bort det k�rbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# '@' medf�r att kommandot inte skrivs ut p� sk�rmen d� det utf�rs av make.
# 'rm' �r ett alias f�r 'rm -i' p� IDA:s system, '\rm' inneb�r att "original-
# versionen", utan skyddsn�tet '-i', anv�nds. Se upp vid �ndring, '*' f�r 
# absolut inte finnas f�r sig!
