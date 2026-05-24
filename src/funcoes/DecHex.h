#ifndef DECHEX_H
#define DECHEX_H

#include <iostream>
#include <string>
using namespace std;

inline string conversaoDecimalHexadecimal(float numero, int type){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;
    string hexadecimalInteiro = "";

    if(parteInteira == 0){
        hexadecimalInteiro = "0";
        if (type == 2) {
            cout << "Parte inteira e 0 -> digito: 0" << endl;
        }
    }

    if (type == 2 && parteInteira > 0) {
        cout << "--- Divisoes Sucessivas (Parte Inteira) ---" << endl;
    }

    string digitosHex = "0123456789ABCDEF";

    while(parteInteira > 0){
        int resto = parteInteira % 16;
        if (type == 2) {
            cout << parteInteira << " / 16 = " << (parteInteira / 16) << " | Resto: " << resto << " -> '" << digitosHex[resto] << "'" << endl;
        }
        hexadecimalInteiro = digitosHex[resto] + hexadecimalInteiro;
        parteInteira /= 16;
    }

    string hexadecimalFracionario = "";
    int limite = 10;

    if (type == 2 && parteFracionaria > 0) {
        cout << "--- Multiplicacoes Sucessivas (Parte Fracionaria) ---" << endl;
    }

    while(parteFracionaria > 0 && limite--){
        float anterior = parteFracionaria;
        parteFracionaria *= 16;
        int digito = (int)parteFracionaria;

        if (type == 2) {
            cout << anterior << " * 16 = " << parteFracionaria << " -> Digito: " << digito << " -> '" << digitosHex[digito] << "'" << endl;
        }

        hexadecimalFracionario += digitosHex[digito];
        parteFracionaria -= digito;
    }

    if (hexadecimalFracionario.length() > 16) {
        hexadecimalFracionario.resize(16);
        cout << endl << "Alerta: Numero truncado para 16 caracteres apos o ponto" << endl << endl << "Resultado:";
    }

    if (type == 2) {
        cout << "--------------------------------------------" << endl;
    }

    if (hexadecimalFracionario.empty()) {
        return hexadecimalInteiro;
    }

    return hexadecimalInteiro + "." + hexadecimalFracionario;
}

#endif