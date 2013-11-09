/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iosfwd>
#include <stdexcept>
#include <string>
#include "Expression_Tree.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <vector>
#include <utility>
#include "../Variable_Table/Variable_Table.h"


class Expression
{
public:
    // Constructor
    Expression(Expression_Tree*);
    Expression() = default;
    // Destructor
    ~Expression();
    
    // Copy constructor
    Expression(const Expression&);
    // Move
    Expression(Expression&&);
    
    // = operator
    Expression& operator=(const Expression&);
    Expression& operator=(Expression&&);
    
    long double evaluate(Variable_Table&) const;
    std::string get_postfix() const;
    std::string get_infix() const;
    bool        empty() const;
    void        print_tree(std::ostream&) const;
    void        swap(Expression&);
    
protected:
	Expression_Tree* tree;
};

/**
 * swap: Byter innehåll på två Expression-objekt.
 */
void swap(Expression&, Expression&);

/**
 * make_expression: Hjälpfunktion för att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en sträng.
 */
Expression make_expression(const std::string& infix);

#endif
