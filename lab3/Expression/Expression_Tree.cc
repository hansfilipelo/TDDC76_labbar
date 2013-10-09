/*
 * Expression_Tree.cc
 */

#include "Expression_Tree.h"

// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

// SEPARATA DEFINITIONER FÖR FÖR EXPRESSION_TREE-KLASSERNA DEFINIERAS HÄR.



//-----------------------INTE GINGER------------------------

//--------------------------------
// Constructor for
Integer::Integer(int inValue){
    value = inValue;
}

//--------------------------------
long double Integer::evaluate() const{
    return double(value);
}


string Integer::get_postfix() const{
    return str();
}

//-------------------------------

string Integer::str() const {
    string result;
    ostringstream convert;
    
    convert << value;
    result = convert.str();
    
    return result;
}

//------------------------------
void Integer::print(std::ostream& stream) const{
    stream << str();
    
}
//------------------------------


Expression_Tree* Integer::clone() const {
    return new Integer(value);
}


//----------------------- Binary_Operator -------------------------------------

//--------------------------------
// Constructor for Binary_Operator
Binary_Operator::Binary_Operator(Expression_Tree* leftIn, Expression_Tree* rightIn){
    left = leftIn;
    right = rightIn;
}

//--------------------------------

string Binary_Operator::get_postfix() const{
    
    string result;
    string space = " ";
    
    result.append(left->get_postfix());
    result.append(space);
    result.append(right->get_postfix());
    result.append(space);
    result.append(str());
    
    return result;
}


//------------------------------
void Binary_Operator::print(std::ostream& stream) const{
    stream << str();
    
}


//----------------------- Plus ------------------------

// Constructor for Plus

Plus::Plus(Expression_Tree* leftIn, Expression_Tree* rightIn)
    : Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Plus::clone() const {
    return new Plus(left, right);
}

//-------------------------------

string Plus::str() const {
    string result = "+";
    return result;
}

//--------------------------------

long double Plus::evaluate() const{
    long double result = left->evaluate() + right->evaluate();
    return result;
}
