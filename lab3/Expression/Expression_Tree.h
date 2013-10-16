/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cctype>

/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!


// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{
public:
    virtual long double      evaluate() const = 0;
    virtual std::string      get_postfix() const = 0;
    virtual std::string      str() const = 0;
    virtual void             print(std::ostream&) const = 0;
    virtual Expression_Tree* clone() const = 0;
    virtual void printHelper(std::ostream& stream, int startDepth) const = 0;
};

//------------------------------

class Binary_Operator : public Expression_Tree
{
public:
    // Constructor
    Binary_Operator(Expression_Tree* leftIn, Expression_Tree* rightIn);
    
    // Virtual functions - declared later
    virtual long double      evaluate() const = 0;
    virtual std::string      str() const = 0;
    virtual Expression_Tree* clone() const = 0;
    
    std::string      get_postfix() const;
    void             print(std::ostream& stream) const;
    
protected:
    Expression_Tree* left;
    Expression_Tree* right;
    void printHelper(std::ostream& stream, int startDepth) const;
};

//------------------------------

class Operand : public Expression_Tree
{
public:
    // Virtual functions - declared later
    virtual std::string      str() const = 0;
    virtual Expression_Tree* clone() const = 0;
    virtual long double      evaluate() const = 0;
    
    std::string      get_postfix() const;
    void             print(std::ostream& stream) const;

protected:
    void printHelper(std::ostream& stream, int startDepth) const;
};

class Assign : public Binary_Operator
{
public:
    Assign(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};




//-------------------

class Plus : public Binary_Operator
{
public:
    Plus(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------

class Minus : public Binary_Operator{
public:
    Minus(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------

class Times : public Binary_Operator{
public:
    Times(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};

class Divide : public Binary_Operator{
public:
    Divide(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------


class Power: public Binary_Operator{
public:
    Power(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
};

//--------------------------------
// Integer for representing integer values

class Integer : public Operand {
public:
    // Constructor
    Integer(long long int inValue);
    
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
    
private:
    long long int value;
};

//--------------------------------

class Real : public Operand {
public:
    // Constructor
    Real(long double inValue);
    
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
    
private:
    long double value;
};

//--------------------------------

class Variable : public Operand {
public:
    // Constructor
    Variable(std::string inName, Expression_Tree* inValue = nullptr);
    
    void setValue(Expression_Tree* inValue);
    
    long double      evaluate() const;
    std::string      str() const;
    Expression_Tree* clone() const;
    
private:
    Expression_Tree* value;
    std::string name;
};

#endif
