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
};

class Binary_Operator : public Expression_Tree
{
};

class Operand : public Expression_Tree
{
};

//class Assign : public Binary_Operator
//{ 
//};

class Plus : public Binary_Operator
{
public:
    // Constructor
    Plus(Expression_Tree* leftIn, Expression_Tree* rightIn);
    
    long double      evaluate() const;
    std::string      get_postfix() const;
    std::string      str() const;
    void             print(std::ostream& stream) const;
    Expression_Tree* clone() const;
    
private:
    Expression_Tree* left;
    Expression_Tree* right;
};

//class Minus : public Binary_Operator 
//{
//};
//
//class Times : public Binary_Operator
//{
//};
//
//class Divide : public Binary_Operator
//{
//};
//
//class Power: public Binary_Operator
//{
//};

//--------------------------------
// Integer for representing integer values

class Integer : public Operand {
public:
    // Constructor
    Integer(int inValue);
    
    long double      evaluate() const;
    std::string      get_postfix() const;
    std::string      str() const;
    void             print(std::ostream& stream) const;
    Expression_Tree* clone() const;
    
private:
    int value;
};

//--------------------------------
//
//class Real : public Operand
//{
//};
//
//class Variable : public Operand
//{
//};

#endif
