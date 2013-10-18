/*
 * Expression_Tree.cc
 */

#include "Expression_Tree.h"
using namespace std;

// SEPARATA DEFINITIONER FÖR FÖR EXPRESSION_TREE-KLASSERNA DEFINIERAS HÄR.


//----------------------- Expression tree -------------------------------------------



//----------------------- Operand -------------------------------------------


string Operand::get_postfix() const{
    return str();
}
//------------------------------
string Operand::get_infix_iterator(bool brackets) const{
    //fšr att fŒ kompilatorn att sluta klaga
    if (brackets) {
        return str();
    }
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

string Operand::get_infix() const {
    return get_infix_iterator(0);
}

//----------------------------------------





//-----------------------INTE GINGER------------------------

//--------------------------------
// Constructor for
Integer::Integer(long long int inValue){
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

long double Integer::evaluate(Variable_Table*) const{
    return double(value);
}




//-----------------------Real------------------------

//--------------------------------
// Constructor for Real
Real::Real(long double inValue){
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

Expression_Tree* Real::clone() const {
    return new Real(value);
}

//--------------------------------

long double Real::evaluate(Variable_Table*) const{
    return value;
}


//--------------------Variable--------------------------
Variable::Variable(string inName, Expression_Tree* inValue){
    name = inName;
    value = inValue;
}

//------------------------------
// set value for variable
void Variable::setValue(Expression_Tree* inValue){
    value = inValue;
}

//-------------------------------
// evaluate for varialbe
long double Variable::evaluate(Variable_Table* varTable) const{
    if (value == nullptr){
        return varTable->getVar(name);
    }
    else {
        varTable->addVar(name,value->evaluate(varTable));
        return value->evaluate(varTable);
    }
}


//-------------------------------
// str
string Variable::str() const{
    return name;
}

//------------------------------

Expression_Tree* Variable::clone() const{
    Expression_Tree* newValue = value->clone();
    try {
        return new Variable(name, newValue);
    } catch (bad_alloc) {
        delete newValue;
        throw;
    }
    
    return nullptr;
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


//--------------------------------
string Binary_Operator::get_infix_iterator(bool brackets) const{
    if(brackets){
        string node = "(" + left->get_infix_iterator(bracketsOrNot(left)) + " " + str() + " " + right->get_infix_iterator(bracketsOrNot(right)) + ")";
        return node;
    }
    else{
        string node = left->get_infix_iterator(bracketsOrNot(left)) + " " + str() + " " + right->get_infix_iterator(bracketsOrNot(right));
        return node;
    }
}

//--------------------------------
// HjŠlpfunktion fšr get_infix_iterator
bool Binary_Operator::bracketsOrNot(Expression_Tree* otherExpression) const {
    
    if ( (str() == string("+") || str() == string("-")) && ((otherExpression->str() == string("*")) || (otherExpression->str() == string("/")) || (otherExpression->str() == string("^"))) ) {
        return false;
    }
    
    if ( str() == string("=") ){
        return false;
    }
    
    if ( (str() == string("*") || str() == string("/")) && otherExpression->str() == string("^") ) {
        return false;
    }
    
    return true;
}

//----------------------------------

string Binary_Operator::get_infix() const {
    return get_infix_iterator(0);
}




//--------------------------------
Binary_Operator::~Binary_Operator() {
    clean();
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

//------------------------------

void Binary_Operator::clean() {
    delete left;
    delete right;
}


//----------------------- Plus ------------------------

// Constructor for Plus

Plus::Plus(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{}

//------------------------------

Expression_Tree* Plus::clone() const {
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Plus(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    
    return nullptr;
    
}

//-------------------------------

string Plus::str() const {
    string result = "+";
    return result;
}

//--------------------------------

long double Plus::evaluate(Variable_Table*) const{
    long double result = left->evaluate(Variable_Table*) + right->evaluate(Variable_Table*);
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
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Minus(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    return nullptr;
}

//-------------------------------

string Minus::str() const {
    string result = "-";
    return result;
}

//--------------------------------

long double Minus::evaluate(Variable_Table*) const{
    long double result = left->evaluate(Variable_Table*) - right->evaluate(Variable_Table*);
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
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Times(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    
    return nullptr;
}

//-------------------------------

string Times::str() const {
    string result = "*";
    return result;
}

//--------------------------------

long double Times::evaluate(Variable_Table*) const{
    long double result = left->evaluate(Variable_Table*) * right->evaluate(Variable_Table*);
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
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Divide(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    return nullptr;
}

//-------------------------------

string Divide::str() const {
    string result = "/";
    return result;
}

//--------------------------------

long double Divide::evaluate(Variable_Table*) const{
    // Can't divide by zero
    if ( right->evaluate(Variable_Table*) == 0 ){
        throw expression_error{"Syntax Error: Can't divide by zero"};
    }
    
    long double result = left->evaluate(Variable_Table*) / right->evaluate(Variable_Table*);
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
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Power(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    return nullptr;
}

//-------------------------------

string Power::str() const {
    string result = "^";
    return result;
}

//--------------------------------

long double Power::evaluate(Variable_Table*) const{
    long double result = pow(left->evaluate(Variable_Table*), right->evaluate(Variable_Table*));
    return result;
}



//----------------------- Assign ------------------------

//---------------------
// Constructor for Assign

Assign::Assign(Expression_Tree* leftIn, Expression_Tree* rightIn)
: Binary_Operator(leftIn, rightIn)
{
    // Convert left to Variable
    Variable* leftVariable = dynamic_cast<Variable*>(left);
    
    // Error if not a Variable but other Expression_Tree sub class
    if ( leftVariable == nullptr ) {
        throw expression_error("Det maste vara en variabel till vanster om =");
    }
    
    leftVariable->setValue(right);
}

//------------------------------

Expression_Tree* Assign::clone() const {
    Expression_Tree* newLeft = left->clone();
    
    try {
        Expression_Tree* newRight = right->clone();
        
        try {
            return new Assign(newLeft, newRight);
        } catch (bad_alloc) {
            delete newRight;
            throw;
        }
        
    } catch (bad_alloc) {
        delete newLeft;
        throw;
    }
    
    return nullptr;
}

//-------------------------------

string Assign::str() const {
    string result = "=";
    return result;
}

//--------------------------------

long double Assign::evaluate(Variable_Table*) const{
    return right->evaluate(Variable_Table*);
}
