#ifndef XDEC_H
#define XDEC_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

inline int charParaDigito(char caractere, int baseOrigem) {
    if (caractere >= '0' && caractere <= '9') {
        return caractere - '0';
    } 
    if (baseOrigem == 16 && caractere >= 'A' && caractere <= 'F') {
        return caractere - 'A' + 10;
    }
    return -1; 
}

double conversaoparaDecimal(string numero, int baseOrigem, int type){

    string parteInteira = "";
    string parteFracionaria = "";
    size_t posPonto = numero.find('.');

    if (posPonto != string::npos) {
        parteInteira = numero.substr(0, posPonto);
        parteFracionaria = numero.substr(posPonto + 1);
    } else {
        parteInteira = numero; 
    }

    if (parteFracionaria.length() > 16) {
        parteFracionaria.resize(16);
        cout <<endl<< "Alerta: Número truncado para 16 caracteres após o ponto" << endl<<endl<<"Resultado:";
    }

    double somatorio = 0.0;

    if (type == 2 && !parteInteira.empty()) {
        cout << "--- Teorema Fundamental da Numeracao (Parte Inteira) ---" << endl;
    }

    int tamInteiro = parteInteira.length();
    for (int i = 0; i < tamInteiro; i++) {
        char caractere = parteInteira[tamInteiro - 1 - i];
        int digito = charParaDigito(caractere, baseOrigem);

        if (digito == -1 || digito >= baseOrigem) {
            cout << "Caractere invalido para a base " << baseOrigem << ": " << caractere << endl;
            return -1.0;
        }

        double termo = digito * pow(baseOrigem, i);
        if (type == 2) {
            cout << "Digito '" << caractere << "' de peso " << baseOrigem << "^" << i << " -> " << digito << " * " << pow(baseOrigem, i) << " = " << termo << endl;
        }
        somatorio += termo;
    }

    if (type == 2 && !parteFracionaria.empty()) {
        cout << "--- Teorema Fundamental da Numeracao (Parte Fracionaria) ---" << endl;
    }

    int tamFracionario = parteFracionaria.length();
    for (int i = 0; i < tamFracionario; i++) {
        char caractere = parteFracionaria[i];
        int digito = charParaDigito(caractere, baseOrigem);

        if (digito == -1 || digito >= baseOrigem) {
            cout << "Caractere invalido na fracao para a base " << baseOrigem << ": " << caractere << endl;
            return -1.0;
        }

        double termo = digito * pow(baseOrigem, -(i + 1));
        if (type == 2) {
            cout << "Digito '" << caractere << "' de peso " << baseOrigem << "^-" << (i + 1) << " -> " << digito << " * " << pow(baseOrigem, -(i + 1)) << " = " << termo << endl;
        }
        somatorio += termo;
    }

    if (type == 2) {
        cout << "--------------------------------------------" << endl;
    }

    return somatorio;
}

#endif