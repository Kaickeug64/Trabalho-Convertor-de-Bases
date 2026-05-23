#ifndef HEXOCT_H
#define HEXOCT_H

#include <iostream>
#include <string>
#include "HexBin.h"
using namespace std;
string conversaoHexadecimalOctal(string numero){
   double n = stof(conversaoHexadecimalBinario(numero));
   cout<<"teste :"<<n<<endl;
   return conversaoBinarioOctal(n);
}

#endif