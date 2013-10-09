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
    
    Plus addition(addition2, fyra);
    cout << addition.get_postfix() << endl;
    
    return 0;
}
