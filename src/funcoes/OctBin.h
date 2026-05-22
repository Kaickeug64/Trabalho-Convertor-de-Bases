#ifndef OCTBIN_H
#define OCTBIN_H

#include <iostream>
#include <string>
using namespace std;
string conversaoOctalBinario(float numero){
    // Separar parte inteira e fracionária
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    // Converter parte inteira
    string binarioInteiro = "";
    if(parteInteira == 0) binarioInteiro = "0";

    int n = parteInteira;
    string temp = "";
    while(n > 0){
        int digito = n % 10; // pega o último dígito octal
        string bin = "";
        // Converter dígito octal para 3 bits binários
        for(int i=0; i<3; i++){
            bin = to_string(digito % 2) + bin;
            digito /= 2;
        }
        temp = bin + temp;
        n /= 10;
    }
    binarioInteiro = temp;

    // Converter parte fracionária
    string binarioFracionaria = "";
    float frac = parteFracionaria;
    int limite = 10; // número de casas binárias
    while(frac > 0 && limite--){
        frac *= 10;
        int digito = (int)frac;
        frac -= digito;
        // Converter dígito octal para 3 bits binários
        string bin = "";
        for(int i=0; i<3; i++){
            bin = to_string(digito % 2) + bin;
            digito /= 2;
        }
        binarioFracionaria += bin;
    }

    return binarioInteiro + "." + binarioFracionaria;
}

#endif