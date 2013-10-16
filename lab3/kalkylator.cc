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
	
    Expression_Tree* t{new Plus{new Integer{7}, new Real{3.14}}};
 
    Expression testis{t};
    
    testis.print_tree(cout);
    cout << endl;
    cout << testis.evaluate() << endl;;
    
    return 0;
}
