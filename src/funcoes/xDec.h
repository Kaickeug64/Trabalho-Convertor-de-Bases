#ifndef XDEC_H
#define XDEC_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int conversaoparaDecimal(string numero, int baseOrigem){
    int tamanho = numero.length();
    int somatorio = 0;
    for (int i = 0; i < tamanho; i++) {
        if (baseOrigem == 16) {
            char caractere = numero[tamanho - 1 - i];
            int digito;
            if (caractere >= '0' && caractere <= '9') {
                digito = caractere - '0';
            } else if (caractere >= 'A' && caractere <= 'F') {
                digito = caractere - 'A' + 10;
            } else {
                cout << "Caractere inválido para base 16: " << caractere << endl;
                return -1;
            }
            somatorio += digito * pow(baseOrigem, i);
        } else {
            int digito = (int)(numero[tamanho - 1 - i] - '0');
            somatorio += digito * pow(baseOrigem, i);
        }
    }

    return somatorio;
}

#endif