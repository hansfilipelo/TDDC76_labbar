/*
 * Expression_Tree.cc
 */

#include "Expression_Tree.h"

// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

// SEPARATA DEFINITIONER FÖR FÖR EXPRESSION_TREE-KLASSERNA DEFINIERAS HÄR.

//----------------------- Operand ---------------------------------------

//--------------------------------

string Operand::get_postfix() const{
    return str();
}


//------------------------------
void Operand::printHelper(std::ostream& stream, int startDepth) const{
    stream << setw(startDepth) << str() << endl;
    
}

void Operand::print(std::ostream& stream) const{
    printHelper(stream, 0);
}

//--------------------------------




//-----------------------INTE GINGER------------------------

//--------------------------------
// Constructor for
Integer::Integer(int inValue){
    value = inValue;
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

Expression_Tree* Integer::clone() const {
    return new Integer(value);
}

//--------------------------------

long double Integer::evaluate() const{
    return double(value);
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

void Binary_Operator::printHelper(std::ostream& stream, int startDepth) const{
    // Call next in line for printing
    right->printHelper(stream, (startDepth + 4));
    
    // Print its own stuff
    stream << setw(startDepth + 2) << "/" << endl;
    stream << setw(startDepth) << str() << endl;
    stream << setw(startDepth + 2) << "\\" << endl;
    
    // Print left
    left->printHelper(stream, (startDepth + 4));
}

void Binary_Operator::print(std::ostream& stream) const{
    printHelper(stream, 0);
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
