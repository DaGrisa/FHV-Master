//
// Created by Daniel on 27.01.17.
//

// S --> a | aB
// B --> b | bB
// ignore spaces

#include "../../../../ClionProjects/AphroCite/AphroCite.h"

typedef enum {a, b, end, error, null} TerminalSymbol;

static char* g_input;
static TerminalSymbol actualSymbol = null;

int checkInput(char *input);
static int stateS();
static int stateB();
static int getActualTerminalSymbol();
static int getNextTerminalSymbol();

int main(){
    Assert_True("check valid abb", checkInput("abb"));
    Assert_True("check invalid aabb", !checkInput("aabb"));
    Assert_True("check valid abbbbbb", checkInput("abbbbbb"));
    Assert_True("check valid abaab", !checkInput("abaab"));
    Assert_True("check valid a b bb  bbb   ", checkInput(" a b bb bbb   "));
    Assert_True("check valid ab aa b", !checkInput("ab aa b"));

    int intValue = 3;
    double doubleValue = 11.5674;
    Console_Print_Format("Ergebnis: %f",intValue/doubleValue);
    Console_Print("\n");
    Console_Print_Format("Ergebnis: %f",doubleValue/intValue);
    return EXIT_SUCCESS;
}

int checkInput(char *input) {
    g_input = input;
    return stateS();
}

static int stateS() {
    if(getActualTerminalSymbol() == a){
        switch(getNextTerminalSymbol()) {
            case end:
                return TRUE;
            case b:
                return stateB();
            default:
                return FALSE;
        }
    } else {
        return FALSE;
    }
}

static int stateB() {
    if(getActualTerminalSymbol() == b){
        switch(getNextTerminalSymbol()) {
            case end:
                return TRUE;
            case b:
                return stateB();
            default:
                return FALSE;
        }
    } else {
        return FALSE;
    }
}

static int getActualTerminalSymbol() {
    if(*g_input == 'a'){
        return a;
    } else if (*g_input == 'b') {
        return b;
    } else if(*g_input == '\0'){
        return end;
    } else if (*g_input == ' ') {
        return getNextTerminalSymbol();
    } else {
        return error;
    }
}

static int getNextTerminalSymbol() {
    g_input++;
    actualSymbol = null;
    return getActualTerminalSymbol();
}