#ifndef BINOCT.H
#define BINOCT.H

#include <iostream>
#include <string>
using namespace std;
string conversaoBinarioOctal(float numero){
    // Separar parte inteira e fracionária
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    // Converter parte inteira binária para octal
    string octalInteiro = "";
    if(parteInteira == 0){
		octalInteiro = "0";
	}
    int n = parteInteira;
    string temp = "";
    while(n > 0){
        // Pegar 3 últimos dígitos binários
        int grupo = n % 1000; // 3 dígitos binários
        int decimal = 0, base = 1;
        while(grupo > 0){
            decimal += (grupo % 10) * base;
            base *= 2;
            grupo /= 10;
        }
        temp = to_string(decimal) + temp;
        n /= 1000;
    }
    octalInteiro = temp;

    // Converter parte fracionária binária para octal
    string octalFracionaria = "";
    int limite = 10; // número de casas
    float frac = parteFracionaria;
    while(frac > 0 && limite--){
        frac *= 8;
        int digito = (int)frac;
        octalFracionaria += to_string(digito);
        frac -= digito;
    }

    return octalInteiro + "." + octalFracionaria;
}

#endif