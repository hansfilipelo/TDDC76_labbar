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
    Expression(class Expression_Tree* = nullptr);
    Expression() = default;
    // Destructor
    ~Expression();
    
    Expression(const Expression&);        //Kopieringskonstruktor
    Expression(Expression&&);           //Move
    
    Expression& operator=(const Expression&);        //= operator
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
 * swap: Byter inneh�ll p� tv� Expression-objekt.
 */
void swap(Expression&, Expression&);

/**
 * make_expression: Hj�lpfunktion f�r att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en str�ng.
 */
Expression make_expression(const std::string& infix);

#endif
