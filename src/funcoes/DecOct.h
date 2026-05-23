#ifndef DECOCT_H
#define DECOCT_H

#include <iostream>
#include <string>
using namespace std;
string conversaoDecimalOctal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string octalInteiro = "";
    if(parteInteira == 0){
        octalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        int digito = parteInteira % 8;
        octalInteiro = to_string(digito) + octalInteiro;
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
    
    if (octalFracionario.length() > 16) {
            octalFracionario.resize(16);
            cout <<endl<< "Alerta: Número truncado para 16 caracteres após o ponto" << endl<<endl<<"Resultado:";
        }
    return octalInteiro + "." + octalFracionario;
}

#endif  
