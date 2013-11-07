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
#include <typeinfo>
#include "../Variable_Table/Variable_Table.h"

/*
 * expression_error: kastas om ett fel inträffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT GÖRA!

class expression_error : public std::logic_error
{
public:
    explicit expression_error(const std::string& what_arg) noexcept
    : std::logic_error{what_arg} {}
    
    explicit expression_error(const char* what_arg) noexcept
    : std::logic_error{what_arg} {}
};

// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{
public:
    virtual ~Expression_Tree() {};
    virtual long double         evaluate(Variable_Table&) = 0;
    virtual std::string         get_postfix() const = 0;
    virtual std::string         str() const = 0;
    virtual void                print(std::ostream&) const = 0;
    virtual Expression_Tree*    clone() const = 0;
    virtual void                printHelper(std::ostream& stream, int startDepth) const = 0;
    virtual std::string                 get_infix() const = 0;
    virtual std::string         get_infix_iterator(bool) const = 0;
};

//------------------------------

class Binary_Operator : public Expression_Tree
{
public:
    // Constructor
    Binary_Operator(Expression_Tree* leftIn, Expression_Tree* rightIn);
    // Destructor
    ~Binary_Operator();
    
    // Virtual functions - declared later
//    virtual long double      evaluate(Variable_Table&) const = 0;
//    virtual std::string      str() const = 0;
//    virtual Expression_Tree* clone() const = 0;
    
    std::string      get_postfix() const;
    std::string      get_infix() const;
    void             print(std::ostream& stream) const;
    
    
protected:
    std::string get_infix_iterator(bool) const;
    bool bracketsOrNot(Expression_Tree*) const;
    Expression_Tree* left;
    Expression_Tree* right;
    void printHelper(std::ostream& stream, int startDepth) const;
    void clean();
};

//------------------------------

class Operand : public Expression_Tree
{
public:
    // Virtual functions - declared later
//    virtual std::string      str() const = 0;
//    virtual Expression_Tree* clone() const = 0;
//    virtual long double      evaluate(Variable_Table&) const = 0;
    
    std::string      get_postfix() const;
    void             print(std::ostream& stream) const;
    std::string      get_infix() const;
    
protected:
    void printHelper(std::ostream& stream, int startDepth) const;
    std::string get_infix_iterator(bool) const;
};

//------------------------------

class Assign : public Binary_Operator
{
public:
    Assign(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};




//-------------------

class Plus : public Binary_Operator
{
public:
    Plus(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------

class Minus : public Binary_Operator{
public:
    Minus(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------

class Times : public Binary_Operator{
public:
    Times(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};

class Divide : public Binary_Operator{
public:
    Divide(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};

//-------------------


class Power: public Binary_Operator{
public:
    Power(Expression_Tree* leftIn, Expression_Tree* rightIn);
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
};

//--------------------------------
// Integer for representing integer values

class Integer : public Operand {
public:
    // Constructor
    Integer(long long int inValue);
    
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
    
protected:
    void printHelper(std::ostream& stream, int startDepth) const;
    
private:
    long long int value;
};

//--------------------------------

class Real : public Operand {
public:
    // Constructor
    Real(long double inValue);
    
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
    
protected:
    void printHelper(std::ostream& stream, int startDepth) const;
    
private:
    long double value;
};

//--------------------------------

class Variable : public Operand {
public:
    // Constructor
    Variable(std::string inName);
    
    void setValue(long double inValue, Variable_Table&);
    
    long double      evaluate(Variable_Table&);
    std::string      str() const;
    Expression_Tree* clone() const;
    long double get_value(Variable_Table&);
    
//protected:
//    void printHelper(std::ostream& stream, int startDepth) const;
    
private:
    std::string name;
};

#endif
