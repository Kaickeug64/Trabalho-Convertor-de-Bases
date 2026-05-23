#ifndef OCTHEX_H
#define OCTHEX_H

#include <iostream>
#include <string>
#include "OctBin.h"
#include "BinHex.h"
using namespace std;
string conversaoOctalHexadecimal(string numero){
    numero = conversaoOctalBinario(numero);
    return conversaoBinarioHexadecimal(numero);
}

#endif