#ifndef DECOCT_H
#define DECOCT_H

#include <iostream>
#include <string>
using namespace std;
string conversaoDecimalHexadecimal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string hexadecimalInteiro = "";
    if(parteInteira == 0){
        hexadecimalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        int digito = parteInteira % 16;
        if(digito < 10)
            hexadecimalInteiro = to_string(digito) + hexadecimalInteiro;
        else
            hexadecimalInteiro = char('A' + digito - 10) + hexadecimalInteiro;
        parteInteira /= 16;
    }

    // Conversão da parte fracionária
    string hexadecimalFracionaria = "";
    int limite = 10; // número de casas
    while(parteFracionaria > 0 && limite--){
        parteFracionaria *= 16;
        int digito = (int)parteFracionaria;
        if(digito < 10)
            hexadecimalFracionaria += to_string(digito);
        else
            hexadecimalFracionaria += char('A' + digito - 10);
        parteFracionaria -= digito;
    }

    return hexadecimalInteiro + "." + hexadecimalFracionaria;
}

#endif