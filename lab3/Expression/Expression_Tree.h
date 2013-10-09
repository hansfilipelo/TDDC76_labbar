/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>

/*
 * expression_error: kastas om ett fel intr�ffar i en Expression-operation;
 * ett diagnostiskt meddelande ska skickas med.
 */
// ATT G�RA!


// OBSERVERA: NEDANST�ENDE �R ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass f�r alla tr�dnodklasser.
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

class Assign : public Binary_Operator
{ 
};

class Plus : public Binary_Operator
{ 
};

class Minus : public Binary_Operator 
{
};

class Times : public Binary_Operator
{
};

class Divide : public Binary_Operator
{
};

class Power: public Binary_Operator
{
};

//--------------------------------
// Integer for representing integer values

class Integer : public Operand
{
	public:
		Integer(int inValue);
		long double      evaluate() const = 0;
		std::string      get_postfix() const = 0;
		std::string      str() const = 0;
		void             print(std::ostream&) const = 0;
		Expression_Tree* clone() const = 0;
	private:
		int value;
};

//--------------------------------

class Real : public Operand
{
};

class Variable : public Operand
{
};

#endif
