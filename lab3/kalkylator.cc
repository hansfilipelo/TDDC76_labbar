//
//  lab3.cc
//  
//
//  Created by Erik Ekelund on 10/9/13.
//
//

#include <stdio.h>
#include "Expression/Expression_Tree.h"
using namespace std;

int main() {
    
    Expression_Tree* femma = new Integer(5);
    Expression_Tree* trea = new Integer(3);
    Expression_Tree* fyra = new Integer(4);
    Expression_Tree* addition2 = new Plus(trea,femma);
    
    Plus addition(fyra, addition2);
    cout << addition.get_postfix() << endl;
    cout << endl;
    
    
    addition.print(cout);
    
    return 0;
}
