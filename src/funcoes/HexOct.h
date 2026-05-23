#ifndef HEXOCT_H
#define HEXOCT_H

#include <iostream>
#include <string>
#include "HexBin.h"
using namespace std;
string conversaoHexadecimalOctal(string numero){
   numero = conversaoHexadecimalBinario(numero);
   return conversaoBinarioOctal(numero);
}

#endif