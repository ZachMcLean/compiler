#include <algorithm>
#include "slp.h"


using namespace std;

/* To be implemented by stduents */
void CompoundStm::interp( SymbolTable& symbols )
{
    //stm1, stm2
    stm1->interp(symbols);
    stm2->interp(symbols);
}

/* To be implemented by stduents */
void AssignStm::interp( SymbolTable& symbols )
{

    // Evaluate the Expression
    // Update the value of the variable
    // 
    // Does the variable exist in the symbol table?
    // if (symbols[id] == NULL) {
    //
    // }
    // Variable is already stored in the symbol table.
    symbols[id] = exp->interp(symbols);
}

void PrintStm::interp( SymbolTable& symbols )
{
    exps->interp(symbols);
}

int IdExp::interp( SymbolTable& symbols )
{
	return id; //to avoid compile errors
}

int NumExp::interp( SymbolTable& symbols )
{
	return num; //to avoid compile errors
}


int OpExp::interp( SymbolTable& symbols )
{
    int num;
    // evaluate the left exp save to lr
    // evaluate the left exp save to rr
    // depending on the type of OP, calc lr and rr
    left->interp(symbols);
    right->interp(symbols);
    oper->interp(symbols);

    switch(oper*) {
        case PLUS:
           num = left + right;
            break;
        case MINUS:
            num = left - right;
            break;
        case TIMES:
            num = left * right;
            break;
        case DIV:
           num = left / right; 
            break;
    }
	return 0; //to avoid compile errors}
}

int EseqExp::interp( SymbolTable& symbols )
{
	return 0; //to avoid compile errors
}


void PairExpList::interp( SymbolTable& symbols)
{
}

void LastExpList::interp( SymbolTable& symbols)
{
}

