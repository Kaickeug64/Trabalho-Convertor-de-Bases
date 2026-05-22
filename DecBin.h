#ifndef DECBIN.H
#define DECBIN.H

#include <iostream>
#include <string>
using namespace std;
inline string conversaoDecimalBinario(float numero) {

    // Parte inteira
    int parteInteira = (int)numero;

    // Parte decimal
    float parteFracionaria = numero - parteInteira;

    string binarioInteiro = "";

    // Conversão da parte inteira
    if (parteInteira == 0) {
        binarioInteiro = "0";
    }

    while (parteInteira > 0) {
        binarioInteiro = to_string(parteInteira % 2) + binarioInteiro;
        parteInteira /= 2;
    }

    // Conversão da parte fracionária
    string binarioFracionario = "";

    int limite = 10; // quantidade de casas binárias

    while (parteFracionaria > 0 && limite--) {

        parteFracionaria *= 2;

        if (parteFracionaria >= 1) {
            binarioFracionario += "1";
            parteFracionaria -= 1;
        } else {
            binarioFracionario += "0";
        }
    }

    return binarioInteiro + "." + binarioFracionario;
}


#endif