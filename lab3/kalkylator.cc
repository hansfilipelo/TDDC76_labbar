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
    
    Plus addition(femma, trea);
    cout << addition.get_postfix() << endl;
    
    return 0;
}
