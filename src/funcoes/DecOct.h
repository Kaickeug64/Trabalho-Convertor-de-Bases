#ifndef DECOCT_H
#define DECOCT_H

#include <iostream>
#include <string>
using namespace std;

string conversaoDecimalOctal(float numero, int type){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;
    string octalInteiro = "";

    if(parteInteira == 0){
        octalInteiro = "0";
        if (type == 2) {
            cout << "Parte inteira e 0 -> digito: 0" << endl;
        }
    }

    if (type == 2 && parteInteira > 0) {
        cout << "--- Divisoes Sucessivas (Parte Inteira) ---" << endl;
    }

    while(parteInteira > 0){
        int digito = parteInteira % 8;
        if (type == 2) {
            cout << parteInteira << " / 8 = " << (parteInteira / 8) << " | Resto: " << digito << endl;
        }
        octalInteiro = to_string(digito) + octalInteiro;
        parteInteira /= 8;
    }

    string octalFracionario = "";
    int limite = 10;

    if (type == 2 && parteFracionaria > 0) {
        cout << "--- Multiplicacoes Sucessivas (Parte Fracionaria) ---" << endl;
    }

    while(parteFracionaria > 0 && limite--){
        float anterior = parteFracionaria;
        parteFracionaria *= 8;
        int digito = (int)parteFracionaria;

        if (type == 2) {
            cout << anterior << " * 8 = " << parteFracionaria << " -> Digito: " << digito << endl;
        }

        octalFracionario += to_string(digito);
        parteFracionaria -= digito;
    }
    
    if (octalFracionario.length() > 16) {
        octalFracionario.resize(16);
        cout << endl << "Alerta: Numero truncado para 16 caracteres apos o ponto" << endl << endl << "Resultado:";
    }

    if (type == 2) {
        cout << "--------------------------------------------" << endl;
    }

    if (octalFracionario.empty()) {
        return octalInteiro;
    }

    return octalInteiro + "." + octalFracionario;
}

#endif