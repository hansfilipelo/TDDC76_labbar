//
//  lab3.cc
//  
//
//  Created by Erik Ekelund on 10/9/13.
//
//

#include <stdio.h>
#include "Expression/Expression_Tree.h"
#include "Expression/Expression.h"
using namespace std;

int main() {
    
    string uttryck = "(1 + 2) * 3 * 4 / 2";
    
    Expression exp = make_expression(uttryck);
    
    exp.print_tree(cout);
    cout << endl;
    exp.evaluate();
    
    return 0;
}
