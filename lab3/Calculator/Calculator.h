/*
 * Calculator.h
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "../Expression/Expression.h"
#include <iosfwd>
#include "../Variable_Table/Variable_Table.h"
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * Calculator: klass för att läsa in, lagra och bearbeta enkla aritmetiska
 * uttryck. För att använda kalylatorn - skapa ett Calculator-objekt och
 * anropa run().
 *
 * Anm: move-konstruktorn och move-illdelningsoperatorn genereras inte om
 * en destruktor, kopieringskonstruktor eller kopieringstilldelnings-
 * operator deklareras.
 */
class Calculator
{
public:
    Calculator() = default;
    ~Calculator() = default;
    
    void run();
    
private:
    // Error class
    class calculator_error : public std::logic_error
    {
    public:
        explicit calculator_error(const std::string& what_arg) noexcept
        : std::logic_error{what_arg} {}
        
        explicit calculator_error(const char* what_arg) noexcept
        : std::logic_error{what_arg} {}
    };
    
    Calculator(const Calculator&) = delete;
    Calculator& operator=(const Calculator&) = delete;
    // Move-konstruktor och move-tilldelning genereras inte.
    
    static const std::string valid_cmds_;
    
    Expression current_expression_;
    
    char command_;
    
    static void print_help();
    
    void get_command();
    bool valid_command() const;
    void execute_command();
    unsigned expPos;
    unsigned currExpNr;
    
    void read_expression(std::istream&);
    
    Variable_Table varTable;
    std::vector<Expression> expVec;
};

#endif
