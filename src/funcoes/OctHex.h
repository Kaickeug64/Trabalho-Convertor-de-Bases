#ifndef OCTHEX_H
#define OCTHEX_H

#include <iostream>
#include <string>
#include "OctBin.h"
using namespace std;
string conversaoOctalHexadecimal(string numero){
    numero = conversaoOctalBinario(stof(numero));
    numero.pop_back();
    return conversaoBinarioHexadecimal(numero);
}

#endif