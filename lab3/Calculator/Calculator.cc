/*
 * Calculator.cc
 */
#include "Calculator.h"

using namespace std;

const string Calculator::valid_cmds_("?HUBPTSILRAVXN");

//// -----------------------------------
//// Constructor
//Calculator::Calculator() {
//    varTable = new Variable_Table();
//}
//
//// -----------------------------------
//// Destructor
//Calculator::~Calculator() {
//    delete varTable;
//}



// -----------------------------------


/**
 * run: Huvudfunktionen f�r kalkylatorn. Skriver ut hj�lpinformation
 * och l�ser sedan sedan in ett kommando i taget och utf�r det.
 */
void Calculator::run()
{
    cout << "V�lkommen till Kalkylatorn!\n\n";
    print_help();
    
    do
    {
        try
        {
            get_command();
            if (valid_command()) execute_command();
        }
        catch (const exception& e)
        {
            cout << e.what() << '\n';
        }
        // Of�rutsedda undantag avbryter programk�rningen, via main().
    }
    while (command_ != 'S');
}

/**
 * print_help: Skriver ut kommandorepertoaren.
 */
void
Calculator::
print_help()
{
    cout << "  H, ?  Skriv ut denna information\n";
    cout << "  U     Mata in ett nytt uttryck\n";
    cout << "  B     Ber�kna aktuellt uttryck\n";
    cout << "  P     Visa aktuellt uttryck som postfix\n";
    cout << "  I     Visa aktuellt uttryck som infix\n";
    cout << "  I n   Visa uttryck n som infix\n";
    cout << "  L     Lista alla uttryck som infix\n";
    cout << "  T     Visa aktuellt uttryck som tr�d\n";
    cout << "  N     Visa antal lagrade uttryck\n";
    cout << "  A n   G�r uttryck n till aktuellt uttryck\n";
    cout << "  R     Radera aktuellt uttryck\n";
    cout << "  R n   Radera uttryck n\n";
    cout << "  V     Lista alla variabler\n";
    cout << "  X     Radera alla variabler\n";
    
    cout << "  S     Avsluta kalkylatorn\n";
}

/**
 * get_command: L�ser ett kommando (ett tecken), g�r om till versal och lagrar
 * kommandot i medlemmen command_, f�r vidare behandling av andra operationer.
 * Ingen kontroll g�rs om det skrivits mer, i s� fall skr�p, p� kommandoraden.
 */
void
Calculator::
get_command()
{
    cout << ">> ";
    cin >> command_;
    string digits;
    expPos = 0;
    
    if ( cin.peek() != '\n' ) {
        
        // Remove one whitespace
        if ( cin.peek() == ' ' ){
            cin.get();
        }
        
        while (cin.peek() != '\n') {
            if (isdigit(cin.peek())){
                digits += cin.get();
            }
            else{
                throw calculator_error{"Endast siffror accepteras som andra argument"};
            }
        }
        
        expPos = stoi(digits);
        if (expPos > expVec.size() || expPos < 1 )
        {
            throw calculator_error{"Ogilitg position angiven."};
        }
    }
    
    command_ = toupper(command_);
}

/**
 * valid_command: Kontrollerar om kommandot som finns i medlemmen command_
 * tillh�r den till�tna kommandorepertoraren och returnerar antingen true
 * (giltigt kommando) eller false (ogiltigt kommando).
 */
bool
Calculator::
valid_command() const
{
    if (valid_cmds_.find(command_) == string::npos)
    {
        cout << "Otill�tet kommando: " << command_ << "\n";
        return false;
    }
    return true;
}

/**
 * execute_command: Utf�r kommandot som finns i medlemmen command_. Kommandot
 * f�ruts�tts ha kontrollerats med valid_command() och allts� �r ett giltigt
 * kommando.
 */
void
Calculator::
execute_command()
{
    if (command_ == 'H' || command_ == '?')
        print_help();
    
    else if (command_ == 'U'){
        read_expression(cin);
        expVec.push_back(current_expression_);
        currExpNr = expVec.size();
    }
    else if (command_ == 'B' && expPos > 0)
        cout << expVec.at(expPos - 1).evaluate(varTable) << "\n";
    else if (command_ == 'B')
        cout << current_expression_.evaluate(varTable) << "\n";
    
    else if (command_ == 'P' && expPos > 0)
        cout << expVec.at(expPos - 1).get_postfix() << "\n";
    else if (command_ == 'P')
        cout << current_expression_.get_postfix() << "\n";
    
    else if (command_ == 'I' && expPos > 0)
        cout << expVec.at(expPos - 1).get_infix() << "\n";
    else if (command_ == 'I')
        cout << current_expression_.get_infix() << "\n";
    
    else if (command_ == 'R' && expPos > 0){
        int i = expPos; //vector.erase() can't take unsigned
        expVec.erase(expVec.begin() + i - 1);
    }
    
    else if (command_ == 'R'){
        current_expression_ = NULL;
        expVec.erase(expVec.begin() + currExpNr - 1); //m�ste fixa denna fkn, raderar ej aktuellt uttryck
    }
    
    else if (command_ == 'A' && expPos > 0){
        currExpNr = expPos;
        current_expression_ = expVec.at(expPos - 1);
        cout << current_expression_.get_infix() << "\n";
    }
    
    else if (command_ == 'T')
        current_expression_.print_tree(cout);
    else if (command_ == 'T' && expPos > 0)
        expVec.at(expPos - 1).print_tree(cout);
    
    else if (command_ == 'V')
        varTable.print();
    
    else if (command_ == 'L' ){
        for (unsigned i = 0 ; i < expVec.size() ; i++) {
            cout << (i + 1) << ": " << expVec.at(i).get_infix() << endl;
        }
    }
    else if (command_ == 'X'){
        varTable.clear();
    }
    
    else if (command_ == 'N')
        cout << expVec.size() << "\n";
    
    else if (command_ == 'S')
        cout << "Kalkylatorn avlutas, v�lkommen �ter!\n";
    else
        cout << "Detta ska inte h�nda!\n";
}

/**
 * read_expression: l�ser ett infixuttryck fr�n instr�mmen is och ger detta
 * till funktionen make_expression() som returnerar ett objekt av typen
 * Expression, vilket lagras som "aktuellt uttryck" i current_expression_.
 */
void
Calculator::
read_expression(istream& is)
{
    string infix;
    
    is >> ws;
    
    if (getline(is, infix))
    {
        current_expression_ = make_expression(infix);
    }
    else
    {
        cout << "Felaktig inmatning!\n";
    }
}
