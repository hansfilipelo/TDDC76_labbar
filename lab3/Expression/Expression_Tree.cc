/*
 * Expression_Tree.cc
 */

#include "Expression_Tree.h"

// INKLUDERA F�R DET SOM KOMMER ATT ANV�NDAS I DENNA FIL!
using namespace std;

// SEPARATA DEFINITIONER F�R F�R EXPRESSION_TREE-KLASSERNA DEFINIERAS H�R.

//----------------------- Operand -------------------------------------------

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




//-----------------------Real------------------------

//--------------------------------
// Constructor for Real
Real::Real(double inValue){
    value = inValue;
}


//-------------------------------

string Real::str() const {
    string result;
    ostringstream convert;
    
    convert << value;
    result = convert.str();
    
    return result;
}

//------------------------------

Expression_Tree* Integer::clone() const {
    return new Real(value);
}

//--------------------------------

long double Real::evaluate() const{
    return value;
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



//----------------------- Minus ------------------------

//---------------------
// Constructor for Minus

Minus::Minus(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Minus::clone() const {
    return new Minus(left, right);
}

//-------------------------------

string Minus::str() const {
    string result = "-";
    return result;
}

//--------------------------------

long double Minus::evaluate() const{
    long double result = left->evaluate() - right->evaluate();
    return result;
}




//----------------------- Times ------------------------

//---------------------
// Constructor for Times

Times::Times(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Times::clone() const {
    return new Times(left, right);
}

//-------------------------------

string Times::str() const {
    string result = "*";
    return result;
}

//--------------------------------

long double Times::evaluate() const{
    long double result = left->evaluate() * right->evaluate();
    return result;
}



//----------------------- Divide ------------------------

//---------------------
// Constructor for Divide

Divide::Divide(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Divide::clone() const {
    return new Divide(left, right);
}

//-------------------------------

string Divide::str() const {
    string result = "/";
    return result;
}

//--------------------------------

long double Divide::evaluate() const{
    // Can't divide by zero
    if ( right->evaluate() == 0 ){
        throw logic_error{"Syntax Error: Can't divide by zero"};
    }
    
    long double result = left->evaluate() / right->evaluate();
    return result;
}


//----------------------- Power ------------------------

//---------------------
// Constructor for Power

Power::Power(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Power::clone() const {
    return new Power(left, right);
}

//-------------------------------

string Power::str() const {
    string result = "^";
    return result;
}

//--------------------------------

long double Power::evaluate() const{
    long double result = pow(left->evaluate(), right->evaluate());
    return result;
}


//
////----------------------- Assign ------------------------
//
////---------------------
//// Constructor for Assign
//
//Assign::Assign(Variable* leftIn, Expression_Tree* rightIn)
//: Binary_Operator(leftIn, rightIn)
//{}
//
////------------------------------
//
//Expression_Tree* Assign::clone() const {
//    return new Assign(left, right);
//}
//
////-------------------------------
//
//string Assign::str() const {
//    string result = "=";
//    return result;
//}
//
////--------------------------------
//
//Assign::evaluate() const{
//    left->setValue(right);
//}