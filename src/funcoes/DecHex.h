#ifndef DECHEX_H
#define DECHEX_H

#include <iostream>
#include <string>
using namespace std;
inline string conversaoDecimalOctal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string octalInteiro = "";
    if(parteInteira == 0){
        octalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        octalInteiro = to_string(parteInteira % 8) + octalInteiro;
        parteInteira /= 8;
    }

    // Conversão da parte fracionária
    string octalFracionario = "";
    int limite = 10; // número de casas
    while(parteFracionaria > 0 && limite--){
        parteFracionaria *= 8;
        int digito = (int)parteFracionaria;
        octalFracionario += to_string(digito);
        parteFracionaria -= digito;
    }

    return octalInteiro + "." + octalFracionario;
}

#endif