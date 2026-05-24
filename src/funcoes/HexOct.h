#ifndef HEXOCT_H
#define HEXOCT_H

#include <iostream>
#include <string>
#include "HexBin.h"
#include "BinOct.h"
using namespace std;

string conversaoHexadecimalOctal(string numero, int type){
   if (type == 2) {
      cout << "=== CONVERSAO: HEXADECIMAL -> BINARIO ===" << endl;
   }
   numero = conversaoHexadecimalBinario(numero, type);
   
   if (type == 2) {
      cout << endl << "=== CONVERSAO: BINARIO -> OCTAL ===" << endl;
   }
   return conversaoBinarioOctal(numero, type);
}

#endif