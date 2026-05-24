#ifndef OCTHEX_H
#define OCTHEX_H

#include <iostream>
#include <string>
#include "OctBin.h"
#include "BinHex.h"
using namespace std;

string conversaoOctalHexadecimal(string numero, int type){
    if (type == 2) {
        cout << "=== CONVERSAO: OCTAL -> BINARIO ===" << endl;
    }
    numero = conversaoOctalBinario(numero, type);
    
    if (type == 2) {
        cout << endl << "=== CONVERSAO: BINARIO -> HEXADECIMAL ===" << endl;
    }
    return conversaoBinarioHexadecimal(numero, type);
}

#endif