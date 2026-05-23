#ifndef DECHEX_H
#define DECHEX_H

#include <iostream>
#include <string>
using namespace std;
inline string conversaoDecimalHexadecimal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string hexadecimalInteiro = "";
    if(parteInteira == 0){
        hexadecimalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        hexadecimalInteiro = to_string(parteInteira % 16) + hexadecimalInteiro;
        parteInteira /= 16;
    }

    // Conversão da parte fracionária
    string hexadecimalFracionario = "";
    int limite = 10; // número de casas
    while(parteFracionaria > 0 && limite--){
        parteFracionaria *= 16;
        int digito = (int)parteFracionaria;
        hexadecimalFracionario += to_string(digito);
        parteFracionaria -= digito;
    }
    if (hexadecimalFracionario.length() > 16) {
            hexadecimalFracionario.resize(16);
            cout <<endl<< "Alerta: Número truncado para 16 caracteres após o ponto" << endl<<endl<<"Resultado:";
        }
    return hexadecimalInteiro + "." + hexadecimalFracionario;
}

#endif